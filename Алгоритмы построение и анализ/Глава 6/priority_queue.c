#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 3
#define K 2

struct hope_list
{
	int key;
	int data;
};

struct hope_list heap_maximum(struct hope_list* list, int size);
struct hope_list heap_minimum(struct hope_list* list, int size);
struct hope_list* heap_extract_max(struct hope_list* list, struct hope_list* bufer, int size);
struct hope_list* heap_extract_min(struct hope_list* list, struct hope_list* bufer, int size);
struct hope_list* max_heap_insert(struct hope_list* list, int key, int size);
struct hope_list* delete_heap_node(struct hope_list* list, int index, int size);
struct hope_list* two_heap_integration(struct hope_list* list1, struct hope_list* list2, int size1, int size2);
void heap_increase_key(struct hope_list* list, int index, int key, int size);
void heap_sort_min_max(struct hope_list* list, int size);
void heap_sort_max_min(struct hope_list* list, int size);
void max_haep_recursion(struct hope_list* list, int root, int size);
int max_haep_recursion_return(struct hope_list* list, int root, int size);
void min_haep_recursion(struct hope_list* list, int root, int size);

int main(void)
{
	struct hope_list* list1;
	struct hope_list* list2;
	list1 = (struct hope_list*)malloc(N * sizeof(struct hope_list));
	list2 = (struct hope_list*)malloc(K * sizeof(struct hope_list));
	printf("KEY   DATA\n");
	for (int i = 0; i < N; i++)
		scanf("%d%d", &list1[i].key, &list1[i].data);
	printf("KEY   DATA\n");
	for (int i = 0; i < K; i++)
		scanf("%d%d", &list2[i].key, &list2[i].data);

	list1 = (struct hope_list*)realloc(list1, (N + K) * sizeof(struct hope_list));
	list1 = two_heap_integration(list1, list2, N, K);

	for (int i = 0; i < N + K; i++)
		printf("%d %d\n", list1[i].key, list1[i].data);
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

struct hope_list* heap_extract_max(struct hope_list* list, struct hope_list* bufer, int size)
{
	if (size <= 1)
		exit(0);

	heap_sort_max_min(list, size);
	*bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	max_haep_recursion(list, 0, size - 1);
	return list;
}

struct hope_list* heap_extract_min(struct hope_list* list, struct hope_list* bufer, int size)
{
	if (size <= 1)
		exit(0);

	heap_sort_min_max(list, size);
	*bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	max_haep_recursion(list, 0, size - 1);
	return list;
}

void heap_increase_key(struct hope_list* list, int index, int key, int size)
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
		max_haep_recursion(list, index, size);
		index = (index - 1) / 2;
	}
}

struct hope_list* max_heap_insert(struct hope_list* list, int key, int size)
{
	list = (struct hope_list*)realloc(list, (size + 1) * sizeof(struct hope_list));
	list[size].key = INT_MIN;
	heap_increase_key(list, size, key, size + 1);
	return list;
}

int max_haep_recursion_return(struct hope_list* list, int root, int size)
{

	int max_number = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int out;
	struct hope_list bufer;


	if (left < size && list[left].key > list[max_number].key)
		max_number = left;
	if (right < size && list[right].key > list[max_number].key)
		max_number = right;
	out = max_number;
	if (max_number != root)
	{
		bufer = list[root];
		list[root] = list[max_number];
		list[max_number] = bufer;
		out = max_haep_recursion_return(list, max_number, size);
	}
	return out;
}

struct hope_list* delete_heap_node(struct hope_list* list, int index, int size)
{
	struct hope_list bufer;
	list[index].key = INT_MIN;
	index = max_haep_recursion_return(list, index, size);
	while (index < size - 1)
	{
		bufer = list[index];
		list[index] = list[index + 1];
		list[index + 1] = bufer;
		index++;
	}
	return (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));;
}

struct hope_list* two_heap_integration(struct hope_list* list1, struct hope_list* list2, int size1, int size2)
{
	list1 = (struct hope_list*)realloc(list1, (size1 + size2) * sizeof(struct hope_list));

	for (int i = 0; i < size2; i++)
		list1[size1 + i] = list2[i];
	heap_sort_min_max(list1, size1 + size2);

	return list1;
}