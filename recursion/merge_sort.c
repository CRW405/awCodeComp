#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int start, int mid, int end) {
	int i, j, k;
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	int leftArr[leftSize], rightArr[rightSize];

	// copy
	for (i = 0; i < leftSize; i++) {
		leftArr[i] = arr[start + i];
	}
	for (j = 0; j < rightSize; j++) {
		rightArr[j] = arr[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = start;
	
	// zipper merge and order
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	
	// fill rest
	while (i < leftSize) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void sort(int arr[], int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		sort(arr, start, mid);
		sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main(int argc, char *argv[])
{
	int n = 10;

	if (argc > 1) {
		n = atoi(argv[1]);
	}

	int arr[n];
	srand(time(NULL));

	printf("%s\n", "unsorted");
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (n+1);
	}

	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	
	sort(arr, 0, n - 1);

	printf("\n\n\n%s\n", "sorted");
	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	return EXIT_SUCCESS;
}
