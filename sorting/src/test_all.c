#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#include "include/selection_sort.h"
#include "include/bubble_sort.h"
#include "include/insertion_sort.h"
#include "include/merge_sort.h"


void verify_sort(char name[], int a[], size_t len) { 
	bool res = true;
	for(unsigned int i = 0; i < len; i++) {
		if(a[i] != i) {
			res = false; 
			break;
		}
	}
	if(res) printf("%s works!\n", name);
	else printf("%s does not work!\n", name);
}

int main() {
	int nums[] = {3, 4, 2, 1, 0, 6, 5, 7, 9, 8};
	size_t len = sizeof(nums)/sizeof(nums[0]);
	int nums_copy[len];
	memcpy(nums_copy, nums, sizeof(nums));
	
	selection_sort(nums_copy, len);
	verify_sort("Selection Sort", nums_copy, len);
	memcpy(nums_copy, nums, sizeof(nums));

	bubble_sort(nums_copy, len);
	verify_sort("Bubble Sort", nums_copy, len);
	memcpy(nums_copy, nums, sizeof(nums));

	insertion_sort(nums_copy, len);
	verify_sort("Insertion Sort", nums_copy, len);
	memcpy(nums_copy, nums, sizeof(nums));

	merge_sort(nums_copy, len);
	verify_sort("Merge Sort", nums_copy, len);
	memcpy(nums_copy, nums, sizeof(nums));

	return 0;
}

