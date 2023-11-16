#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void swap(int* x, int* y);
void quicksotr(int* arr, int size);
void quicksotr_recurion(int* arr, int low, int high);
int* partition(int* arr, int low, int high);


int main(void)
{
	int arr[N] = { 10, 4, 5, 6, 4, 10, 4, 5, 6, 9 };
	//arr = (int*)malloc(N * sizeof(int));
	srand(time(NULL));
	//for (int i = 0; i < N; i++)
	//	arr[i] = rand();;
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
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
	if (low < high)
	{

		int* pivot;
		pivot = (int*)malloc(2 * sizeof(int));
		pivot = partition(arr, low, high);
		printf("%d %d\n", pivot[0], pivot[1]);
		if (pivot[1] == pivot[0])
		{
			quicksotr_recurion(arr, low, pivot[0] - 1);
			quicksotr_recurion(arr, pivot[0] + 1, high);
		}
		else if (pivot[1] > pivot[0])
		{
			quicksotr_recurion(arr, low, pivot[1] - 1);
			quicksotr_recurion(arr, pivot[1] + 1, high);
		}
	}
}

int* partition(int* arr, int low, int high)
{
	int pivot_index;
	pivot_index = high;
	if (pivot_index != high)
		swap(arr + pivot_index, arr + high);

	int pivot = arr[high];
	int* j;
	j = (int*)malloc(2 * sizeof(int));
	j[0] = low;
	for (int i = low; i < high; i++)
	{
		//printf("%d ", j[0]);
		if (arr[i] < pivot)
		{
			swap(&arr[j[0]], arr + i);
			j[0]++;
			j[1] = j[0];
		}
		else if (arr[i] == pivot)
		{
			swap(&arr[j[1]], arr + i);
			j[1]++;
		}
	}
	swap(arr + j[0], arr + high);
	getchar();
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return j;
}