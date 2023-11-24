#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int* x, int* y);
int rand_quick_select(int* arr, int size, int num);
int rand_quick_select_recurion(int* arr, int low, int high, int num);
int rand_partition(int* arr, int low, int high);


int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
		arr[i] = rand();
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n%d", rand_quick_select(arr, N, 0));
	return 0;
}
void swap(int* x, int* y)
{
	int bufer = *x;
	*x = *y;
	*y = bufer;
}

int rand_partition(int* arr, int low, int high)
{
	int pivot_index;
	pivot_index = low + (rand() % (high - low));
	if (pivot_index != high)
		swap(arr + pivot_index, arr + high);

	int pivot = arr[high];
	int j = low;
	for (int i = low; i < high; i++)
		if (arr[i] <= pivot)
		{
			swap(arr + j, arr + i);
			j++;
		}

	swap(arr + j, arr + high);

	return j;
}

int rand_quick_select(int* arr, int size, int num)
{
	srand((unsigned int)time(NULL));
	return rand_quick_select_recurion(arr, 0, size - 1, num);
}

int rand_quick_select_recurion(int* arr, int low, int high, int num)
{
	int pivot;
	int num_bufer;

	while (true)
	{
		if (low == high)
			return arr[low];
		pivot = rand_partition(arr, low, high);
		num_bufer = pivot - low + 1;
		if (num == num_bufer)
			return arr[pivot];
		if (num < num_bufer)
			high = pivot - 1;
		else
		{
			low = pivot + 1;
			num = num - num_bufer;
		}
	}
}