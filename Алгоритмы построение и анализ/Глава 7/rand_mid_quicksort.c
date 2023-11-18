#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int* x, int* y);
int medium(int* arr, int i, int j, int k);
void rand_quicksotr(int* arr, int size);
void rand_quicksotr_recurion(int* arr, int low, int high);
int rand_partition(int* arr, int low, int high);


int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
		arr[i] = rand();
	rand_quicksotr(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}
void swap(int* x, int* y)
{
	if (x == y)
		return;
	int bufer = *x;
	*x = *y;
	*y = bufer;
}

int medium(int* arr, int i, int j, int k)
{
	int mid = i;
	arr[i] > arr[j] && arr[i] < arr[k] ? mid = i : 0;
	arr[i] < arr[j] && arr[i] > arr[k] ? mid = i : 0;
	arr[j] > arr[i] && arr[j] < arr[k] ? mid = j : 0;
	arr[j] < arr[i] && arr[j] > arr[k] ? mid = j : 0;
	arr[k] > arr[j] && arr[k] < arr[i] ? mid = k : 0;
	arr[k] < arr[j] && arr[k] > arr[i] ? mid = k : 0;

	arr[i] == arr[j] && arr[i] > arr[k] ? mid = k : 0;
	arr[i] == arr[j] && arr[i] < arr[k] ? mid = i : 0;
	arr[i] == arr[k] && arr[i] > arr[j] ? mid = j : 0;
	arr[i] == arr[j] && arr[i] < arr[k] ? mid = i : 0;
	arr[k] == arr[j] && arr[k] > arr[i] ? mid = i : 0;
	arr[k] == arr[j] && arr[i] < arr[k] ? mid = k : 0;

	return mid;
}

void rand_quicksotr(int* arr, int size)
{
	srand((unsigned int)time(NULL));
	rand_quicksotr_recurion(arr, 0, size - 1);
}

void rand_quicksotr_recurion(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = rand_partition(arr, low, high);
		rand_quicksotr_recurion(arr, low, pivot - 1);
		rand_quicksotr_recurion(arr, pivot + 1, high);
	}
}

int rand_partition(int* arr, int low, int high)
{
	if ((high - low) > 3)
	{
		int i, j, k;
		i = low + (rand() % (high - low));
		j = low + (rand() % (high - low));
		k = low + (rand() % (high - low));
		swap(arr + medium(arr, i, j, k), arr + high);
	}

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