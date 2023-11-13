#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 3
#define M 4

int* sort(int* arr, int size);
int search(int* arr, int num, int x, int y);
int heap_extract_min(int* arr, int size);
void heap_sort_max_min(int* arr, int size);
void heap_sort_min_max(int* arr, int size);
void min_haep_recursion(int* arr, int root, int size);
void max_haep_recursion(int* arr, int root, int size);
void max_heap_insert(int* arr, int key, int size);

int main(void)
{
	int a = 1;
	int* arr;
	arr = (int*)malloc(N * M * sizeof(int));

	for (int i = 0; i < N * M; i++, a++)
		arr[i] = a;
	for (int i = 0; i < N * M; i++)
	{
		if ((i % 4 == 0) && (i != 0))
			printf("\n");
		printf("%d ", arr[i]);

	}
	printf("\n%d\n", search(arr, 7, N, M));
	//for (int i = 0; i < N * M; i++)
	//{
	//	if ((i % 4 == 0) && (i != 0))
	//		printf("\n");
	//	printf("%d ", arr[i]);
	//
	//}
	return 0;
}

int heap_extract_min(int* arr, int size)
{
	int bufer;
	if (size <= 1)
		exit(0);

	heap_sort_max_min(arr, size);
	bufer = arr[size - 1];
	arr[size - 1] = INT_MAX;
	heap_sort_min_max(arr, size);
	return bufer;


}

void heap_sort_min_max(int* arr, int size)
{
	int bufer;

	for (int i = size / 2 - 1; i >= 0; i--)
		min_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer = arr[0];
		arr[0] = arr[i];
		arr[i] = bufer;
		min_haep_recursion(arr, 0, i);
	}
}

void heap_sort_max_min(int* arr, int size)
{
	int bufer;

	for (int i = size / 2 - 1; i >= 0; i--)
		max_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer = arr[0];
		arr[0] = arr[i];
		arr[i] = bufer;
		max_haep_recursion(arr, 0, i);
	}
}

void min_haep_recursion(int* arr, int root, int size)
{
	int min_number = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int bufer;

	if (left < size && arr[left] > arr[min_number])
		min_number = left;
	if (right < size && arr[right] > arr[min_number])
		min_number = right;
	if (min_number != root)
	{
		bufer = arr[root];
		arr[root] = arr[min_number];
		arr[min_number] = bufer;
		min_haep_recursion(arr, min_number, size);
	}
}

void max_haep_recursion(int* arr, int root, int size)
{
	int max_number = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int bufer;

	if (left < size && arr[left] < arr[max_number])
		max_number = left;
	if (right < size && arr[right] < arr[max_number])
		max_number = right;
	if (max_number != root)
	{
		bufer = arr[root];
		arr[root] = arr[max_number];
		arr[max_number] = bufer;
		max_haep_recursion(arr, max_number, size);
	}
}

void max_heap_insert(int* arr, int key, int size)
{
	if (arr[size - 1] != INT_MAX)
		exit(2);

	arr[size - 1] = key;
	heap_sort_min_max(arr, size);
}

int* sort(int* arr, int size)
{
	int* arr_return;
	arr_return = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
		arr_return[i] = heap_extract_min(arr, size);

	return arr_return;
}

int search(int* arr, int num, int x, int y)
{
	int i = 0;
	int j = 0;
	while (true)
	{
		if (arr[y * i + x + j] > num)
		{
			i++;
			j = 0;
		}
		if (arr[y * i + x + j] < num)
			j++;
		if (arr[y * i + x + j] == num)
			return y * i + x + j;
		if (i == y - 1 && arr[y * x] != num)
			return -1;
	}
}