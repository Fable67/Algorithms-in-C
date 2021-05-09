## Algorithms in C

This repo consists of some algorithms I coded in **C**.  
I did my best to make them **as efficient as possible**, however, I **do not claim** they are!

## Supported algorithms

- Sorting:
    - Selection Sort
    - Insertion Sort
    - Bubble Sort
    - Merge Sort


- Searching:
    - Linear Search

- Clustering:
    - K-means Clustering

## Installation

```bash
$ make all                // <-- To compile all tests
$ make [algorithm_type]   // <-- To compile specific tests of algorithm types, e.g. sorting, searching, ...
$ make run                // <-- To compile and run all tests
```

## Usage

```c
#include "stddef.h"
#include "stdlib.h"                               
                                                     
#include "include/selection_sort.h"                 
#include "include/insertion_sort.h"
#include "include/bubble_sort.h"
#include "include/merge_sort.h"

#include "include/linear_search.h"

#include "include/k_means_clustering.h"

// Sorting
int nums[] = {3, 4, 2, 1, 0, 6, 5, 7, 9, 8};
size_t len = sizeof(nums)/sizeof(nums[0]);

selection_sort(nums_copy, len);
insertion_sort(nums_copy, len);
bubble_sort(nums_copy, len);
merge_sort(nums_copy, len);

// Searching
int idx = linear_search(nums, 3, len);

// Clustering
k_means_point_t* points[3];
points[0] = k_means_create_point(0.1, 0.8);
points[1] = k_means_create_point(0.5, 0.5);
points[2] = k_means_create_point(0.8, 0.1);

k_means_centroid_t** centroids;
centroids = k_means(points, 3, 1, 0.000001);

k_means_point_t* new_point = k_means_create_point(1.0, 0.0);
size_t cluster_idx = k_means_closest_centroid_idx(centroids, 1, new_point);

free(centroids)
```
This includes most information needed to use the algorithms. If you want to know how they work feel free to look into the source code.

## Contributing
Contributions are happily welcome. For **rather minor changes** like typos and efficiency improvements, just **post a pull request** that includes all necessary information about the change.  
For **major changes** like new algorithms, please **open an issue first** to discuss it.

Please always make sure to **update tests** as appropriate in the respective algorithm type directory. The test file is always named **test_all.c** and holds all tests for the algorithms of that specific type.

## License
[MIT](https://choosealicense.com/licenses/mit/)