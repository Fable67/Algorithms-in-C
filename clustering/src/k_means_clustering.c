#include "time.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#include "include/k_means_clustering.h"

k_means_point_t* k_means_create_point(double x, double y) {
  k_means_point_t* point = malloc(sizeof(k_means_point_t));
  if(point == NULL) return NULL;
  point->x = x;
  point->y = y;
  return point;
}

k_means_centroid_t* k_means_create_centroid(double x, double y) {
  k_means_centroid_t* centroid = malloc(sizeof(k_means_centroid_t));
  if(centroid == NULL) return NULL;
  centroid->x = x;
  centroid->y = y;
  centroid->points = malloc(sizeof(k_means_point_t*) * 100000);
  if(centroid->points == NULL) {
    free(centroid);
    return NULL;
  }
  return centroid;
}

double calculate_distance_squared(double x1, double x2, double y1, double y2) {
  double delta_x = x2 - x1;
  double delta_y = y2 - y1;
  return delta_x*delta_x + delta_y*delta_y;
}

size_t k_means_closest_centroid_idx(k_means_centroid_t** centroids, size_t num_centroids, k_means_point_t* point) {
  if(centroids == NULL || num_centroids == 0 || point == NULL) return 0;
  double closest_centroid_distance = 3;
  size_t closest_centroid_idx = 0;
  double x1 = point->x;
  double y1 = point->y;
  for(size_t j = 0; j < num_centroids; j++) {
    double x2 = centroids[j]->x;
    double y2 = centroids[j]->y;
    double dist = calculate_distance_squared(x1, x2, y1, y2);
    if(dist < closest_centroid_distance) {
      closest_centroid_distance = dist;
      closest_centroid_idx = j;
    }
  }
  return closest_centroid_idx;
}

void centroid_add_point(k_means_centroid_t* centroid, k_means_point_t* point, size_t index) {
  if(centroid == NULL || point == NULL) return;
  centroid->points[index] = point;
  centroid->points = realloc(centroid->points, sizeof(centroid->points) + sizeof(k_means_point_t*));
}

// Note that this algorithm works in a space of 0<=x<=1, 0<=y<=1
k_means_centroid_t** k_means(k_means_point_t** points, size_t num_points, size_t num_centroids, double precision) {
  if(points == NULL || num_points == 0 || num_centroids == 0 || precision <= 0) return NULL;
  time_t t;
  srand((unsigned) time(&t));
  
  // Initialize random starting positions for the centroids
  k_means_centroid_t** centroids = malloc(sizeof(k_means_centroid_t*) * num_centroids);
  for(size_t i = 0; i < num_centroids; i++) {
    double random_x = (double)rand()/RAND_MAX;
    double random_y = (double)rand()/RAND_MAX;
    centroids[i] = k_means_create_centroid(random_x, random_y);
  }
  // Save the positions of the centroids of the last iteration to detect convergence
  size_t* centroids_last_idx = calloc(num_centroids, sizeof(size_t));
  k_means_point_t** centroids_last_points = malloc(sizeof(k_means_point_t*) * num_centroids);
  for(size_t i = 0; i < num_centroids; i++) {
    centroids_last_points[i] = k_means_create_point(centroids[i]->x, centroids[i]->y);
  }

  bool is_converged = false;
  while(!is_converged) {  
    // Determine the closest centroid for each point
    for(size_t i = 0; i < num_points; i++) {
      size_t closest_centroid_idx = k_means_closest_centroid_idx(centroids, num_centroids, points[i]);
      centroid_add_point(centroids[closest_centroid_idx], points[i], centroids_last_idx[closest_centroid_idx]++);

    }

    // Move the centroids to the mean position of its points
    for(size_t i = 0; i < num_centroids; i++) {
      double mean_x = 0;
      double mean_y = 0;
      for(size_t j = 0; j < centroids_last_idx[i]; j++) {
        mean_x += centroids[i]->points[j]->x;
        mean_y += centroids[i]->points[j]->y;
      }
      mean_x /= centroids_last_idx[i] + 1e-12;
      mean_y /= centroids_last_idx[i] + 1e-12;
      centroids[i]->x = mean_x;
      centroids[i]->y = mean_y;
      centroids_last_idx[i] = 0;
      centroids[i]->points = realloc(centroids[i]->points, sizeof(k_means_point_t*));
    }

    // Check for convergence
    bool local_converged = true;
    for(size_t i = 0; i < num_centroids; i++) {
      double x1 = centroids[i]->x;
      double y1 = centroids[i]->y;
      double x2 = centroids_last_points[i]->x;
      double y2 = centroids_last_points[i]->y;
      if(calculate_distance_squared(x1, x2, y1, y2) > precision) {
        local_converged = false;
        break;
      }
    }
    is_converged = local_converged;

    // Save the centroids position 
    for(size_t i = 0; i < num_centroids; i++) {
      centroids_last_points[i]->x = centroids[i]->x; 
      centroids_last_points[i]->y = centroids[i]->y;
    }

  }

  free(centroids_last_idx);
  free(centroids_last_points);

  return centroids;
}

