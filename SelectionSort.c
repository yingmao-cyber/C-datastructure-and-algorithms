
#include<stdio.h>

void print_arr(int index, int* arr, int end) {
	printf("%i: ", index);
	for (int i = 0; i <= end; i++) {
		printf("%i, ", arr[i]);
	}
	printf("\n");
}

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void iterative_selection_sort(int* arr, int end) {
	for (int i = 0; i < end; i++) {
		int min_index = i;
		for (int j = i + 1; j <= end; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(&arr[i], &arr[min_index]);
		}

		print_arr(i, arr, end);

	}
}

void recursive_selection_sort(int* arr, int start, int end) {
	if (start == end) {
		return;
	}
	int min_index = start;
	for (int j = start + 1; j <= end; j++) {
		if (arr[j] < arr[min_index]) {
			min_index = j;
		}
	}
	if (min_index != start) {
		swap(&arr[start], &arr[min_index]);
	}
	print_arr(start, arr, end);

	recursive_selection_sort(arr, start + 1, end);
}

int main() {
	// Time Complexity:
	// Worst Case: O(n^2); Best Case: O(n^2)
	int arr1[] = { 5, 4, 3, 6, 1, 2 };
	int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
	iterative_selection_sort(arr1, end);
	recursive_selection_sort(arr1, 0, end);

	return 0;
}
