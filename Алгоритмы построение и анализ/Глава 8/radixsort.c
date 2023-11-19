#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 100

void radix_sort(int* arr, int size);
void count_sort(int* arr, int size, int dis);


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
	radix_sort(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}

void radix_sort(int* arr, int size)
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	for (int i = 1; (max / i) > 0; i *= 10)
		count_sort(arr, size, i);
}

void count_sort(int* arr, int size, int dis)
{
	int* arr_output;
	int* arr_dis_num;
	arr_output = (int*)malloc(size * sizeof(int));
	arr_dis_num = (int*)calloc(10, sizeof(int));

	for (int i = 0; i < size; i++)
		arr_dis_num[(arr[i] / dis) % 10]++;
	for (int i = 1; i < 10; i++)
		arr_dis_num[i] += arr_dis_num[i - 1];
	for (int i = size - 1; i >= 0; i--)
	{
		arr_output[arr_dis_num[(arr[i] / dis) % 10] - 1] = arr[i];
		arr_dis_num[(arr[i] / dis) % 10]--;
	}
	for (int i = 0; i < size; i++)
		arr[i] = arr_output[i];

	free(arr_output);
	free(arr_dis_num);
}