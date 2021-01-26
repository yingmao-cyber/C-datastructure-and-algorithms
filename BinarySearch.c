
#include <stdio.h>

void iterative_binary_search(int arr[], int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) {
			printf("Found target value %i at index %i\n", arr[mid], mid);
			return;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
			printf("value: %i, new start=%i, end=%i\n", arr[mid], start, end);
		}
		else {
			end = mid - 1;
			printf("value: %i, new start=%i, end=%i\n", arr[mid], start, end);
		}
	}
	printf("Not Found.");
	return;
}

void recursive_binary_search(int arr[], int start, int end, int target) {
	if (start > end) {
		printf("Not Found.");
		return;
	}
	int mid = (start + end) / 2;
	if (arr[mid] == target) {
		printf("Found target value %i at index %i\n", arr[mid], mid);
		return;
	}
	else if (arr[mid] < target) {
		start = mid + 1;
		printf("value: %i, new start=%i, end=%i\n", arr[mid], start, end);
	}
	else {
		end = mid - 1;
		printf("value: %i, new start=%i, end=%i\n", arr[mid], start, end);
	}
	recursive_binary_search(arr, start, end, target);
}

int main() {
	// Time Complexity:
	// Worst case: O(log(n)); Best case: O(1)
	int arr[] = { 3, 5, 6, 9, 10, 11 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	//iterative_binary_search(arr, 0, arr_size - 1, 12);
	//recursive_binary_search(arr, 0, arr_size - 1, 8);
	recursive_binary_search(arr, 0, arr_size - 1, 11);

	return 0;
}
