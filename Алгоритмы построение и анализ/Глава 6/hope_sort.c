#include <stdlib.h>
#include <stdio.h>
#define N 10

void max_haep_recursion(int* arr, int root, int size);
void min_haep_recursion(int* arr, int root, int size);
void heap_sort(int* arr, int size);

int main(void)
{
	int* arr;
	arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	heap_sort(arr, N);
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}

void max_haep_recursion(int* arr, int root, int size)
{
	int max_number = root;
	int left = 2 * root;
	int right = 2 * root + 1;
	int bufer;

	if (left < size && arr[left] > arr[max_number])
		max_number = left;
	if (right < size && arr[right] > arr[max_number])
		max_number = right;
	if (max_number != root)
	{
		bufer = arr[root];
		arr[root] = arr[max_number];
		arr[max_number] = bufer;
		max_haep_recursion(arr, max_number, size);

	}

}

void min_haep_recursion(int* arr, int root, int size)
{
	int min_number = root;
	int left = 2 * root;
	int right = 2 * root + 1;
	int bufer;

	if (left < size && arr[left] < arr[min_number])
		min_number = left;
	if (right < size && arr[right] < arr[min_number])
		min_number = right;
	if (min_number != root)
	{
		bufer = arr[root];
		arr[root] = arr[min_number];
		arr[min_number] = bufer;
		min_haep_recursion(arr, min_number, size);

	}

}


void heap_sort(int* arr, int size)
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