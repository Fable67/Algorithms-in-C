#include "linear_search.h"

int linear_search(const int nums[], const int item, const size_t len) {
	for(int i = 0; i < len; i++) {
		if(nums[i] == item) return i;
	}
	return -1;
}

