##include <stdio.h>
#include <stdlib.h>
#define N 3

struct hope_list
{
	int key;
	int data;
};

int heap_maximum(struct hope_list* list, int size);
int heap_extract_max(int* arr, int size);
void heap_sort_min_max(int* arr, int size);
void heap_sort_max_min(int* arr, int size);
void max_haep_recursion(int* arr, int root, int size);
void min_haep_recursion(int* arr, int root, int size);

int main(void)
{
	struct hope_list list[N];

	printf("KEY   DATA\n");
	for (int i = 0; i < N; i++)
		scanf("%d%d", &list[i].key, &list[i].data);

	printf("%d", heap_maximum(list));

	//for (int i = 0; i <= 3; i++)
	//	printf("%d\n", heap_extract_max(arr, (N / 2) - i));

	//for (int i = 0; i < N / 2; i++)
	//	printf("%d   %d\n", arr[i], arr[i + 1]);
	return 0;
}



int heap_maximum(struct hope_list* list, int size)
{
	heap_sort_max_min(list, size);
	return arr[0];
}

void max_haep_recursion(int* arr, int root, int size)
{

	int max_number = root;
	int left = 2 * root;
	int right = 2 * root + 1;
	int* bufer;
	bufer = (int*)malloc(2 * sizeof(int));

	if (left < size && arr[left] > arr[max_number])
		max_number = left;
	if (right < size && arr[right] > arr[max_number])
		max_number = right;
	if (max_number != root)
	{
		bufer[0] = arr[root];
		bufer[1] = arr[root + 1];
		arr[root] = arr[max_number];
		arr[root + 1] = arr[max_number + 1];
		arr[max_number] = bufer[0];
		arr[max_number + 1] = bufer[1];
		max_haep_recursion(arr, max_number, size);
	}
	free(bufer);
}

void heap_sort_min_max(int* arr, int size)
{
	int* bufer;
	bufer = (int*)malloc(2 * sizeof(int));

	for (int i = size / 2 - 1; i >= 0; i--)
		min_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer[0] = arr[0];
		bufer[1] = arr[1];
		arr[0] = arr[i];
		arr[1] = arr[i + 1];
		arr[i] = bufer[0];
		arr[i + 1] = bufer[1];
		min_haep_recursion(arr, 0, i);
	}
	free(bufer);
}

void heap_sort_max_min(int* arr, int size)
{
	struct hope_list bufer;

	for (int i = size / 2 - 1; i >= 0; i--)
		max_haep_recursion(arr, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer[0] = arr[0];
		bufer[1] = arr[1];
		arr[0] = arr[i];
		arr[1] = arr[i + 1];
		arr[i] = bufer[0];
		arr[i + 1] = bufer[1];
		max_haep_recursion(arr, 0, i);
	}
}

void min_haep_recursion(int* arr, int root, int size)
{
	int min_number = root;
	int left = 2 * root;
	int right = 2 * root + 1;
	int* bufer;
	bufer = (int*)malloc(2 * sizeof(int));

	if (left < size && arr[left] < arr[min_number])
		min_number = left;
	if (right < size && arr[right] < arr[min_number])
		min_number = right;
	if (min_number != root)
	{
		bufer[0] = arr[root];
		bufer[1] = arr[root + 1];
		arr[root] = arr[min_number];
		arr[root + 1] = arr[min_number + 1];
		arr[min_number] = bufer[0];
		arr[min_number + 1] = bufer[1];
		min_haep_recursion(arr, min_number, size);
	}
}

int heap_extract_max(int* arr, int size)
{
	if (size < 1)
		return printf("Очередь пуста\n");

	getchar();
	printf("%d ", arr[0]);
	heap_sort_min_max(arr, size);
	int max;
	max = arr[0];
	arr[0] = arr[size * 2 - 1];
	arr[1] = arr[size * 2];
	arr = (int*)realloc(arr, (size - 1) * 2 * sizeof(int));
	max_haep_recursion(arr, 0, size - 1);
	return max;
}
