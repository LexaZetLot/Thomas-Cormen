#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 8
#define D 3

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
	struct hope_list bufer;
	int a = 10;
	struct hope_list* list;
	struct hope_list* list_new;
	list = (struct hope_list*)malloc(N * sizeof(struct hope_list));
	list_new = (struct hope_list*)malloc((N - 1) * sizeof(struct hope_list));
	for (int i = 0; i < N; i++, a--)
	{
		list[i].key = a;
		list[i].data = 0;
	}
	for (int i = 0; i < N; i++)
		printf("%d %d\n", list[i].key, list[i].data);
	printf("***********\n");
	list_new = heap_extract_min(list, &bufer, N);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", list_new[i].key, list_new[i].data);
	printf("***********\n");
	printf("%d %d\n", bufer.key, bufer.data);
	return 0;
}

void max_haep_recursion(struct hope_list* list, int root, int size)
{
	int max_number = root;
	struct hope_list bufer;

	for (int i = 1; i < D + 2; i++)
		if ((list[D * root + i].key < list[max_number].key) && ((D * root + i) < size))
			max_number = D * root + i;

	if (max_number != root)
	{
		bufer = list[root];
		list[root] = list[max_number];
		list[max_number] = bufer;
		max_haep_recursion(list, max_number, size);
	}
}

void min_haep_recursion(struct hope_list* list, int root, int size)
{
	int min_number = root;
	struct hope_list bufer;

	for (int i = 1; i < D + 2; i++)
		if ((list[D * root + i].key > list[min_number].key) && ((D * root + i) < size))
			min_number = D * root + i;

	if (min_number != root)
	{
		bufer = list[root];
		list[root] = list[min_number];
		list[min_number] = bufer;
		min_haep_recursion(list, min_number, size);
	}
}

void heap_sort_min_max(struct hope_list* list, int size)
{
	struct hope_list bufer;
	for (int i = size / D - 1; i >= 0; i--)
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
	for (int i = size / D - 1; i >= 0; i--)
		max_haep_recursion(list, i, size);
	for (int i = size - 1; i >= 0; i--)
	{
		bufer = list[0];
		list[0] = list[i];
		list[i] = bufer;
		max_haep_recursion(list, 0, i);
	}
}

struct hope_list* heap_extract_max(struct hope_list* list, struct hope_list* bufer, int size)
{
	if (size <= 1)
		exit(0);

	heap_sort_min_max(list, size);
	*bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	heap_sort_max_min(list, size - 1);

	return list;
}

struct hope_list* heap_extract_min(struct hope_list* list, struct hope_list* bufer, int size)
{
	if (size <= 1)
		exit(0);

	heap_sort_max_min(list, size);
	*bufer = list[size - 1];
	list = (struct hope_list*)realloc(list, (size - 1) * sizeof(struct hope_list));
	heap_sort_max_min(list, size - 1);
	return list;
}
