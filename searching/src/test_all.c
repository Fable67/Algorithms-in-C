#include "stdio.h"

#include "include/linear_search.h"

void verify_search(char name[], int idx) { 
	if(idx == 5) printf("%s works!\n", name);
	else printf("%s does not work!\n", name);
}

int main() {
	int nums[] = {3, 4, 2, 1, 0, 5, 6, 7, 9, 8};
	size_t len = sizeof(nums)/sizeof(nums[0]);
	
	verify_search("Linear Search", linear_search(nums, 5, len));

	return 0;
}