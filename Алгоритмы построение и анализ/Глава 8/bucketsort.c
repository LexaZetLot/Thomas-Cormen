#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 100

void backetsort(float* arr, int size);
void swap(float* x, float* y);
void rand_quicksotr(float* arr, int size);
void rand_quicksotr_recurion(float* arr, int low, int high);
int rand_partition(float* arr, int low, int high);

int main(void)
{
	float buf;
	float* arr;
	arr = (float*)malloc(N * sizeof(float));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
	{
		if (((buf = (float)(rand() % 10)) != 0) && (buf != 1.000000f))
			arr[i] = 1 / buf;
		else
			i--;
	}
	for (int i = 0; i < N; i++)
		printf("%f ", arr[i]);
	printf("\n*****************\n");
	backetsort(arr, N);
	for (int i = 0; i < N; i++)
		printf("%f ", arr[i]);

	return 0;
}

void backetsort(float* arr, int size)
{
	float* arr_buf;
	arr_buf = (float*)calloc(size * size, sizeof(float));
	for (int i = 0; i < size; i++)
	{
		int j = (int)(size * arr[i]);
		for (int k = 0; k < size; k++)
			if (arr_buf[j * size + k] == 0)
			{
				arr_buf[j * size + k] = arr[i];
				break;
			}
	}

	for (int i = 0; i < size; i++)
		rand_quicksotr(arr_buf + (i * size), size);

	{
		int i = 0;
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
			{
				if (arr_buf[j * size + k] != 0)
					arr[i++] = arr_buf[j * size + k];
			}
	}
}

void swap(float* x, float* y)
{
	float bufer = *x;
	*x = *y;
	*y = bufer;
}

void rand_quicksotr(float* arr, int size)
{
	srand((unsigned int)time(NULL));
	rand_quicksotr_recurion(arr, 0, size - 1);
}

void rand_quicksotr_recurion(float* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = rand_partition(arr, low, high);
		rand_quicksotr_recurion(arr, low, pivot - 1);
		rand_quicksotr_recurion(arr, pivot + 1, high);
	}
}

int rand_partition(float* arr, int low, int high)
{
	int pivot_index;
	pivot_index = low + (rand() % (high - low));
	if (pivot_index != high)
		swap(arr + pivot_index, arr + high);

	float pivot = arr[high];
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