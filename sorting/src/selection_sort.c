#include "selection_sort.h"

void selection_sort (int nums[], const size_t len) {
	int min_elem, temp;
	unsigned int min_idx;

	for(unsigned int i = 0; i < len; i++) {
		min_elem = 100000;
		min_idx = 0;
		for(unsigned int j = i; j < len; j++) {
			if(nums[j] < min_elem) {
				min_elem = nums[j];
				min_idx = j;
			}
		}
		temp = nums[i];
		nums[i] = min_elem;
		nums[min_idx] = temp;
	}
}
