#include "include/bubble_sort.h"

void bubble_sort(int nums[], const size_t len) {
	int temp;
	for(unsigned int i = 0; i < len; i++) {
		for(unsigned int j = len-1; j > i; j--) {
			if(nums[j] < nums[j-1]) {
				temp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = temp;
			}
		}	
	}
}