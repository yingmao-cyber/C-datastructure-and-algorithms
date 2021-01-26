
#include<stdio.h>

void print_arr(int index, int* arr, int end) {
	printf("%i: ", index);
	for (int i = 0; i <= end; i++) {
		printf("%i, ", arr[i]);
	}
	printf("\n");
}

void iterative_insertion_sort(int* arr, int end) {
	for (int i = 1; i <= end; i++) {
		int key = arr[i];
		int j = i - 1;
		// shift elements larger than key to the right of the key
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		// insert key
		arr[j + 1] = key;
		print_arr(i, arr, end);
	}
}

void recursive_insertion_sort_1(int* arr, int start, int end) {
	int key = arr[start + 1];
	int j = start;
	// shift elements larger than key to the right of the key
	while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
		j--;
	}
	// insert key
	arr[j + 1] = key;
	print_arr(start, arr, end);

	start = start + 1;
	if (start < end) {
		recursive_insertion_sort_1(arr, start, end);
	}
}

void recursive_insertion_sort_2(int* arr, int end) {
	if (end < 1) {
		return;
	}

	recursive_insertion_sort_2(arr, end - 1);

	int key = arr[end];
	int j = end - 1;
	// shift elements larger than key to the right of the key
	while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
		j--;
	}
	// insert key
	arr[j + 1] = key;
	print_arr(end, arr, end);

}

int main() {
	// Time Complexity:
	// Worst Case: O(n^2); Best Case: O(n^2)
	int arr1[] = { 5, 4, 3, 6, 1, 2 };
	int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
	iterative_insertion_sort_1(arr1, end);
	recursive_insertion_sort_2(arr1, end);
	return 0;
}
