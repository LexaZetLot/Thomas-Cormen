#include <stdio.h>
#include <stdlib.h>
#define N 3

struct hope_list
{
	int key;
	int data;
};

struct hope_list heap_maximum(struct hope_list* list, int size);
struct hope_list heap_minimum(struct hope_list* list, int size);
struct hope_list heap_extract_max(struct hope_list* list, int size);
struct hope_list heap_extract_min(struct hope_list* list, int size);
void heap_increase_key(struct hope_list* list, int index, int key);
void heap_sort_min_max(struct hope_list* list, int size);
void heap_sort_max_min(struct hope_list* list, int size);
void max_haep_recursion(struct hope_list* list, int root, int size);
void min_haep_recursion(struct hope_list* list, int root, int size);

int main(void)
{
	struct hope_list* list;
	struct hope_list bufer;
	list = (struct hope_list*)malloc(N * sizeof(struct hope_list));
	printf("KEY   DATA\n");
	for (int i = 0; i < N; i++)
		scanf("%d%d", &list[i].key, &list[i].data);

	bufer = heap_minimum(list, N);

	printf("%d %d", bufer.key, bufer.data);
	return 0;
}



struct hope_list heap_maximum(struct hope_list* list, int size)
{
	max_haep_recursion(list, 0, size);
	return list[0];
}

struct hope_list heap_minimum(struct hope_list* list, int size)
{
	min_haep_recursion(list, 0, size);
	return list[0];
}

void max_haep_recursion(struct hope_list* list, int root, int size)
{

	int max_number = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	struct hope_list bufer;


	if (left < size && list[left].key > list[max_number].key)
		max_number = left;
	if (right < size && list[right].key > list[max_number].key)
		max_number = right;
	if (max_number != root)
	{
		bufer = list[root];
		list[root] = list[max_number];
		list[max_number] = bufer;
		max_haep_recursion(list, max_number, size);
	}
}

void heap_sort_min_max(struct hope_list* list, int size)
{
	struct hope_list bufer;

	for (int i = size / 2 - 1; i >= 0; i--)
		min_haep_recursion(list, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer = list[0];
		list[0] = list[i];
		list[i] = bufer;
		min_haep_recursion(list, 0, i);
	}
}

void heap_sort_max_min(struct hope_list* list, int size)
{
	struct hope_list bufer;

	for (int i = size / 2 - 1; i >= 0; i--)
		max_haep_recursion(list, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer = list[0];
		list[0] = list[i];
		list[i] = bufer;
		max_haep_recursion(list, 0, i);
	}
}

void min_haep_recursion(struct hope_list* list, int root, int size)
{
	int min_number = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	struct hope_list bufer;


	if (left < size && list[left].key < list[min_number].key)
		min_number = left;
	if (right < size && list[right].key < list[min_number].key)
		min_number = right;
	if (min_number != root)
	{
		bufer = list[root];
		list[root] = list[min_number];
		list[min_number] = bufer;
		min_haep_recursion(list, min_number, size);
	}
}

struct hope_list heap_extract_max(struct hope_list* list, int size)
{
	struct hope_list bufer;
	if (size <= 1)
		exit(0);

	heap_sort_max_min(list, size);
	bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	max_haep_recursion(list, 0, size - 1);
	return bufer;
}

struct hope_list heap_extract_min(struct hope_list* list, int size)
{
	struct hope_list bufer;
	if (size <= 1)
		exit(0);

	heap_sort_min_max(list, size);
	bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	max_haep_recursion(list, 0, size - 1);
	return bufer;
}

void heap_increase_key(struct hope_list* list, int index, int key)
{
	struct hope_list bufer;
	if (key < list[index].key)
		exit(1);

	list[index].key = key;
	while (index > 0 && list[(index - 1) / 2].key < list[index].key)
	{
		bufer = list[index];
		list[index] = list[(index - 1) / 2];
		list[(index - 1) / 2] = bufer;
		index = (index - 1) / 2;
	}
}