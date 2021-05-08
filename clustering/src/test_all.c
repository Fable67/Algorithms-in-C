#include "stdio.h"
#include "stdlib.h"

#include "include/k_means_clustering.h"

int main() {

	k_means_point_t* points[1];
	points[0] = k_means_create_point(0.6, 0.7);

	k_means_centroid_t** centroids;
	centroids = k_means(points, 1, 1, 0.000001);

	if(abs(0.6 - centroids[0]->x) <= 0.000001 && abs(0.7 - centroids[0]->y) <= 0.000001) {
		printf("K-Means Clustering works!\n");
	} else {
		printf("K-Means Clustering does not work!\n");
	}

	free(centroids);

	return 0;
}