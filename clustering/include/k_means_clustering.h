#ifndef K_MEANS_CLUSTERING_H
#define K_MEANS_CLUSTERING_H

#include "stddef.h"

typedef struct K_MEANS_POINT_STRUCT  {
  double x;
  double y;
} k_means_point_t;

typedef struct K_MEANS_CENTROID_STRUCT {
  double x;
  double y;
  k_means_point_t** points;
} k_means_centroid_t;

k_means_point_t* k_means_create_point(double x, double y);

k_means_centroid_t* k_means_create_centroid(double x, double y);

size_t k_means_closest_centroid_idx(k_means_centroid_t** centroids, size_t num_centroids, k_means_point_t* point);

k_means_centroid_t** k_means(k_means_point_t** points, size_t num_points, size_t num_centroids, double precision);


#endif
