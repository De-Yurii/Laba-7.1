#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define N 10000
void InsertSort(int arr[], int n)
{
	int key, i;
	for (int k = 1; k < n; k++) {
		key = arr[k];
		i = k - 1;
		while ((i >= 0) && (arr[i] < key)) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int array[], int low, int high) {

	int pivot = array[high];

	int i = (low - 1);
	for (int j = low; j < high; j++) {
		if (array[j] >= pivot) {

			i++;

			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		int pi = partition(array, low, high);

		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

int isarrays_equal(int arr1[N], int arr2[N]) {
	int result = 1;
	for (int i = 0; i < N; i++) {
		result = result && (arr1[i] == arr2[i]);
	}
	return result;
}

int main() {
	int some;
	scanf("%d", &some);
	int arr1[N];
	int arr_original[N];
	int n = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < n; i++) {
		arr1[i] = rand() % n;
	}
	for (int i = 0; i < N; i++) {
		arr_original[i] = arr1[i];
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr1[i]);
	}
	printf("Is arrays Equal: %d\n", isarrays_equal(arr1, arr_original));
	clock_t start = clock();
	printf("Insert Sort:  \n");

	start = clock();

	InsertSort(arr1, n);
	clock_t end = clock();
	for (int i = 0; i < N; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	double time_insert = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	quickSort(arr_original, 0, N - 1);
	end = clock();
	for (int i = 0; i < N; i++) {
		printf("%d ", arr_original[i]);
	}
	printf("\n");
	double time_quicksort = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Is arrays Equal: %d\n", isarrays_equal(arr1, arr_original));
	printf("The Insert Search : %lf \nThe Quick sort: %lf", time_insert, time_quicksort);
}