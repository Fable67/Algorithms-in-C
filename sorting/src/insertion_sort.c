#include "insertion_sort.h"

void insertion_sort(int nums[], const size_t len) {
	int temp;
	for(unsigned int i = 1; i < len; i++) {
		for(unsigned int j = i; j > 0; j--) {
			if(nums[j] < nums[j-1]) {
				temp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = temp;
			} else {
				break;
			}
		}
	}
}

