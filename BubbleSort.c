
#include<stdio.h>

void print_arr(int* arr, int end) {
	for (int i = 0; i <= end; i++) {
		printf("%i, ", arr[i]);
	}
	printf("\n");
}

void iterative_bubble_sort(int* arr, int end) {
	for (int i = 0; i < end; i++) {
		int count = 0;
		for (int j = 0; j < end - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count += 1;
			}
		}
		printf("%i : arr: ", i);
		print_arr(arr, end);
		if (count == 0) {
			break;
		}
	}
}

void recursive_bubble_sort(int *arr, int end) {
	int count = 0;
	for (int i = 0; i < end; i++) {
		if (arr[i] > arr[i + 1]) {
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			count += 1;
		}
	}
	print_arr(arr, end);
	if (count == 0) {
		return;
	}
	recursive_bubble_sort(arr, end - 1);
}

int main() {
	// Time Complexity of Bubble Sort:
	// Worst case: O(n^2); Best case: O(n)
	int arr1[] = { 5, 4, 3, 6, 1 };
	int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
	recursive_bubble_sort(arr1, end);
	//iterative_bubble_sort(arr1, end);
	//printf("\n");

	int arr2[] = { 1, 2, 10, 9, 8, 50 };
	end = sizeof(arr2) / sizeof(arr2[0]) - 1;
	recursive_bubble_sort(arr2, end);
	//iterative_bubble_sort(arr2, end);
	//printf("\n");

	int arr3[] = { 1, 2, 3, 4, 5 };
	end = sizeof(arr3) / sizeof(arr3[0]) - 1;
	recursive_bubble_sort(arr3, end);
	//iterative_bubble_sort(arr3, end);
	//printf("\n");

	return 0;
}
