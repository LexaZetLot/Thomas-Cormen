#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 3
#define K 2

int flag_size = 1;

int heap_maximum(int* arr);
int heap_extract_max(int* arr, int size);
void heap_sort_min_max(int* arr, int size);
void heap_sort_max_min(int* arr, int size);
void max_haep_recursion(int* arr, int root, int size);
void min_haep_recursion(int* arr, int root, int size);

int main(void)
{
	int* arr;
	arr = (int*)malloc((N * K) * sizeof(int));

	printf("KEY   DATA\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[N * 0 + i]);
		scanf("%d", &arr[N * 1 + i]);
	}
	for (int i = 0; i <= 3; i++)
		printf("%d\n", heap_extract_max(arr, N - i));
	//printf("%d\n", heap_extract_max(arr, N));
	//printf("%d\n", heap_extract_max(arr, N - 2));
	//printf("%d\n", heap_extract_max(arr, N - 3));
	//printf("\n");
	//for (int i = 0; i < N; i++)
	//	printf("%d   %d\n", arr[N * 0 + i], arr[N * 1 + i]);
	return 0;
}



int heap_maximum(int* arr)
{
	return arr[1];
}

void max_haep_recursion(int* arr, int root, int size)
{
	if (size < 2)
		return;
	else
	{
		int max_number = root;
		int left = 2 * root;
		int right = 2 * root + 1;
		int* bufer;
		bufer = (int*)malloc(K * sizeof(int));

		if (left < size && arr[N * 0 + left] > arr[N * 0 + max_number])
			max_number = left;
		if (right < size && arr[N * 0 + right] > arr[N * 0 + max_number])
			max_number = right;
		if (max_number != root)
		{
			bufer[0] = arr[N * 0 + root];
			bufer[1] = arr[N * 1 + root];
			arr[N * 0 + root] = arr[N * 0 + max_number];
			arr[N * 1 + root] = arr[N * 1 + max_number];
			arr[N * 0 + max_number] = bufer[0];
			arr[N * 1 + max_number] = bufer[1];
			max_haep_recursion(arr, max_number, size);
		}
		free(bufer);
	}
}

void heap_sort_min_max(int* arr, int size)
{
	int* bufer;
	bufer = (int*)malloc(K * sizeof(int));

	for (int i = size / 2 - 1; i >= 0; i--)
		min_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer[0] = arr[N * 0];
		bufer[1] = arr[N * 1];
		arr[N * 0 + 0] = arr[N * 0 + i];
		arr[N * 1 + 0] = arr[N * 1 + i];
		arr[N * 0 + i] = bufer[0];
		arr[N * 1 + i] = bufer[1];
		min_haep_recursion(arr, 0, i);
	}
	free(bufer);
}

void heap_sort_max_min(int* arr, int size)
{
	int* bufer;
	bufer = (int*)malloc(K * sizeof(int));

	for (int i = size / 2 - 1; i >= 0; i--)
		max_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer[0] = arr[N * 0];
		bufer[1] = arr[N * 1];
		arr[N * 0 + 0] = arr[N * 0 + i];
		arr[N * 1 + 0] = arr[N * 1 + i];
		arr[N * 0 + i] = bufer[0];
		arr[N * 1 + i] = bufer[1];
		max_haep_recursion(arr, 0, i);
	}
	free(bufer);
}

void min_haep_recursion(int* arr, int root, int size)
{
	int min_number = root;
	int left = 2 * root;
	int right = 2 * root + 1;
	int* bufer;
	bufer = (int*)malloc(K * sizeof(int));

	if (left < size && arr[N * 0 + left] < arr[N * 0 + min_number])
		min_number = left;
	if (right < size && arr[N * 0 + right] < arr[N * 0 + min_number])
		min_number = right;
	if (min_number != root)
	{
		bufer[0] = arr[N * 0 + root];
		bufer[1] = arr[N * 1 + root];
		arr[N * 0 + root] = arr[N * 0 + min_number];
		arr[N * 1 + root] = arr[N * 1 + min_number];
		arr[N * 0 + min_number] = bufer[0];
		arr[N * 1 + min_number] = bufer[1];
		min_haep_recursion(arr, min_number, size);
	}
}

int heap_extract_max(int* arr, int size)
{
	if (size < 1)
	{
		printf("Очередь пуста");
		return 0;
	}
	heap_sort_min_max(arr, size);
	int max;

	max = arr[0 * N + 0];
	arr[0 * N + 0] = arr[0 * N + size];
	arr[1 * N + 0] = arr[1 * N + size];
	arr = (int*)realloc(arr, (size - 1) * 2 * sizeof(int));
	printf("%d ", arr[size - 1]);
	max_haep_recursion(arr, 0, size - 1);
	flag_size++;
	return max;
}

