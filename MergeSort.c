#include<stdio.h>

void print_arr(int* arr, int size_of_arr) {
	for (int i = 0; i < size_of_arr; i++) {
		printf("%i, ", arr[i]);
	}
	printf("\n");
}

int merge(int *arr, int start, int mid, int end) {
	int left_arr_size = mid - start + 1;
	int right_arr_size = end - mid;
	printf("left_arr_size: %i\n", left_arr_size);
	printf("right_arr_size: %i\n", right_arr_size);
	int *L = malloc(left_arr_size * sizeof(int)); // create left temp array
	int *R = malloc(right_arr_size * sizeof(int)); // create right temp array

	if (L == NULL || R == NULL) {
		printf("Not enough memory. Aborted.");
		free(L);
		free(R);
		return -1;
	}

	// Copy values into temp sub arrays
	for (int i = 0; i < left_arr_size; i++) {
		L[i] = arr[start + i];
	}
	for (int j = 0; j < right_arr_size; j++) {
		R[j] = arr[mid + 1 + j];
	}


	int l = 0; // 1st index of left sub array
	int r = 0; // 1st index of right sub array
	int k = start; // 1st index of merged array

	while (l < left_arr_size && r < right_arr_size) {
		if (L[l] <= R[r]) {
			arr[k] = L[l];
			l++;
		}
		else {
			arr[k] = R[r];
			r++;
		}
		k++;
	}

	// Copy the remaining values from left sub temp array into merged array
	while (l < left_arr_size) {
		arr[k] = L[l];
		l++;
		k++;
	}

	// Copy the remaining values from right sub temp array into merged array
	while (r < right_arr_size) {
		arr[k] = R[r];
		r++;
		k++;
	}

	printf("Left array: \n");
	print_arr(L, left_arr_size);
	printf("Right array: \n");
	print_arr(R, right_arr_size);
	printf("Merged array: \n");
	print_arr(arr, end + 1);
	printf("---------------------");
	printf("\n");

	free(L);
	free(R);
	return 0;
}

void merge_sort(int *arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	int result_code = merge(arr, start, mid, end);
	if (result_code == -1) {
		return;
	}
}

int main() {
	// Time Complexity:
	// Worst Case: O(nlog(n)); Best Case: O(nlog(n))
	int arr1[] = { 5, 4, 3, 6, 1, 2 };
	int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
	merge_sort(arr1, 0, end);

	return 0;
}