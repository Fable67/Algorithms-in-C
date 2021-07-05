#include "include/binary_search.h"

int binary_search(const int nums[], const int item, const size_t len) {
	// The list has to be sorted!
	int start_idx = 0;
	int end_idx = len-1;
	int mid_idx = (start_idx+end_idx)/2;
	
	while(1) {
		if(nums[mid_idx] == item) 
			return mid_idx;
		else if(nums[mid_idx] < item) {
			start_idx = mid_idx+1;
		} else {
			end_idx = mid_idx-1;
		}
		if(0 <= start_idx && start_idx < len && 0 <= end_idx && end_idx < len && start_idx <= end_idx) 
			mid_idx = (start_idx+end_idx)/2;
		else 
			return -1;
	}

	return -1;
}
