#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "include/k_means_clustering.h"

int main() {
	k_means_point_t* points[5];
	points[0] = k_means_create_point(0.60001, 0.70005);
	points[1] = k_means_create_point(0.60002, 0.70004);
	points[2] = k_means_create_point(0.60003, 0.70003);
	points[3] = k_means_create_point(0.60004, 0.70002);
	points[4] = k_means_create_point(0.60005, 0.70001);

	k_means_centroid_t** centroids;
	centroids = k_means(points, 5, 1, 0.00000000001);

	if(fabs(0.60003 - centroids[0]->x) <= 0.000001 && fabs(0.70003 - centroids[0]->y) <= 0.000001) {
		printf("K-Means Clustering works!\n");
	} else {
		printf("K-Means Clustering does not work!\n");
		printf("(%f, %f)\n", centroids[0]->x, centroids[0]->y);
	}

	free(centroids);

	return 0;
}
