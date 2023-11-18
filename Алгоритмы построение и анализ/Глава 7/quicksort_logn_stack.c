#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int* x, int* y);
void quicksotr(int* arr, int size);
void quicksotr_recurion(int* arr, int low, int high);
int partition(int* arr, int low, int high);


int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		arr[i] = rand();;
	quicksotr(arr, N);
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

void quicksotr(int* arr, int size)
{
	quicksotr_recurion(arr, 0, size - 1);
}

void quicksotr_recurion(int* arr, int low, int high)
{
	while (low < high)
	{
		int pivot = partition(arr, low, high);
		if (pivot - low < high - pivot)
		{
			quicksotr_recurion(arr, low, pivot - 1);
			low = pivot + 1;
		}
		else
		{
			quicksotr_recurion(arr, pivot + 1, high);
			high = pivot - 1;
		}
	}
}

int partition(int* arr, int low, int high)
{
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