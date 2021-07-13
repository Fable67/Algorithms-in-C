#include "string.h"

#include "merge_sort.h"

void _merge(int nums[], const unsigned int start, const unsigned int mid, const unsigned int end) {
	unsigned int size_l = mid - start + 1;
	unsigned int size_r = end - mid;
	int left[size_l], right[size_r];
	memcpy(left, &nums[start], sizeof(left));
	memcpy(right, &nums[mid+1], sizeof(right));
	int l_idx = 0;
	int r_idx = 0;
	int nums_idx = start;
	while(l_idx < size_l && r_idx < size_r) {
		if(left[l_idx] < right[r_idx]) nums[nums_idx++] = left[l_idx++];
		else nums[nums_idx++] = right[r_idx++];
	}
	while(l_idx < size_l) nums[nums_idx++] = left[l_idx++];
	while(r_idx < size_r) nums[nums_idx++] = right[r_idx++];
}

void _merge_sort(int nums[], const unsigned int start, const unsigned int end) {
	unsigned int mid;

	if(end > start) {
		mid = (start+end)/2;
		_merge_sort(nums, start, mid);
		_merge_sort(nums, mid+1, end);
		_merge(nums, start, mid, end);
	}
}

void merge_sort(int nums[], const size_t len) {
	_merge_sort(nums, 0, len-1);
}

