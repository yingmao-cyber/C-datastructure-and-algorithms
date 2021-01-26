
#include <stdio.h>

void linear_search(int* arr, int arr_size, int target) {
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == target) {
			printf("Found: index = %i\n", i);
			return;
		}
	}
	printf("Not Found\n");
}

int main() {
	// Time Complexity:
	// Worst case: O(n); Best case: O(1)
	int arr[] = { 24, 50, 10, 5, 3 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	linear_search(arr, arr_size, 3);
	linear_search(arr, arr_size, 1);

	return 0;
}
