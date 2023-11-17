#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int* x, int* y);
void rand_quicksotrI(int* arr, int size);
void rand_quicksotr_recurionI(int* arr, int low, int high);
void rand_partitionI(int* arr, int low, int high, int& begin, int& end);


int main(void)
{

	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
		arr[i] = rand();
	rand_quicksotrI(arr, N);
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

void rand_quicksotrI(int* arr, int size)
{
	srand((unsigned int)time(NULL));
	rand_quicksotr_recurionI(arr, 0, size - 1);
}

void rand_quicksotr_recurionI(int* arr, int low, int high)
{
	if (low < high)
	{
		int begin;
		int end;
		rand_partitionI(arr, low, high, begin, end);
		rand_quicksotr_recurionI(arr, low, --begin);
		rand_quicksotr_recurionI(arr, ++end, high);
	}
}

void rand_partitionI(int* arr, int low, int high, int& begin, int& end)
{
	int pivot = arr[low];
	begin = low;
	end = high;

	for (int i = begin + 1; i <= end; i++)
	{
		if (arr[i] < pivot)
		{
			swap(arr + i, arr + begin);
			begin++;
		}
		if (arr[i] > pivot)
		{
			swap(arr + i, arr + end);
			end--;
			i--;
		}
	}
}