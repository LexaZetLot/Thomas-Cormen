#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int* x, int* y);
void revers_rand_quicksotr(int* arr, int size);
void revers_rand_quicksotr_recurion(int* arr, int low, int high);
int revers_rand_partition(int* arr, int low, int high);


int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		arr[i] = rand();
	revers_rand_quicksotr(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}
void swap(int* x, int* y)
{
	int bufer = *x;
	*x = *y;
	*y = bufer;
}

void revers_rand_quicksotr(int* arr, int size)
{
	srand(time(NULL));
	revers_rand_quicksotr_recurion(arr, 0, size - 1);
}

void revers_rand_quicksotr_recurion(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = revers_rand_partition(arr, low, high);
		revers_rand_quicksotr_recurion(arr, low, pivot - 1);
		revers_rand_quicksotr_recurion(arr, pivot + 1, high);
	}
}

int revers_rand_partition(int* arr, int low, int high)
{
	int pivot_index;
	pivot_index = low + (rand() % (high - low));
	if (pivot_index != high)
		swap(arr + pivot_index, arr + high);

	int pivot = arr[high];
	int j = low;
	for (int i = low; i < high; i++)
		if (arr[i] >= pivot)
		{
			swap(arr + j, arr + i);
			j++;
		}

	swap(arr + j, arr + high);

	return j;
}