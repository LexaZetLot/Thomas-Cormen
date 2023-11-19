#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 100

int* countsort(int* arr, int size);

int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
		arr[i] = rand();

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n*****************\n");
	arr = countsort(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}

int* countsort(int* arr, int size)
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	int* bufer;
	bufer = (int*)calloc(max + 1, sizeof(int));

	for (int i = 0; i < size; i++)
		bufer[arr[i]]++;

	for (int i = 1; i <= max; i++)
		bufer[i] += bufer[i - 1];

	int* output;
	output = (int*)malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; i--)
	{
		output[bufer[arr[i]] - 1] = arr[i];
		bufer[arr[i]]--;
	}

	free(bufer);
	return output;
}