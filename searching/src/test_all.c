#include "stdio.h"

#include "include/linear_search.h"
#include "include/binary_search.h"

void verify_search(const char name[], int idx, int desired_idx) { 
	if(idx == desired_idx) printf("%s works!\n", name);
	else printf("%s does not work!\n", name);
}

int main() {
	int nums[] = {3, 4, 2, 1, 0, 5, 6, 7, 9, 8};
	size_t len = sizeof(nums)/sizeof(nums[0]);
	
	verify_search("Linear Search", linear_search(nums, 5, len), 5);
	
	
	int nums2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t len2 = sizeof(nums2)/sizeof(nums2[0]);

	verify_search("Binary Search", binary_search(nums2, 8, len2), 7);

	return 0;
}
