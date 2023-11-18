#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

struct arr_list
{
	int a;
	int b;
};

void swap(struct arr_list* x, struct arr_list* y);
void fuzzsort(struct arr_list* arr, int size);
void fuzzsort_recurion(struct arr_list* arr, int low, int high);
void find_intersection(struct arr_list* arr, int low, int high, int& a, int& b);
int partition_right(struct arr_list* arr, int a, int low, int high);
int partition_left(struct arr_list* arr, int b, int low, int high);

int main(void)
{
	struct arr_list* arr;
	arr = (struct arr_list*)malloc(N * sizeof(struct arr_list));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
	{
		arr[i].a = rand();
		arr[i].b = arr[i].a + rand();
	}
	for (int i = 0; i < N; i++)
		printf("%d %d\n", arr[i].a, arr[i].b);
	printf("************\n");
	fuzzsort(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", arr[i].a, arr[i].b);
	return 0;
}
void swap(struct arr_list* x, struct arr_list* y)
{
	if (x == y)
		return;
	struct arr_list bufer = *x;
	*x = *y;
	*y = bufer;
}

void fuzzsort(struct arr_list* arr, int size)
{
	srand((unsigned int)time(NULL));
	fuzzsort_recurion(arr, 0, size - 1);
}
void fuzzsort_recurion(struct arr_list* arr, int low, int high)
{
	if (low < high)
	{
		int a, b;
		int pivot_t;
		int pivot_q;
		find_intersection(arr, low, high, a, b);
		pivot_t = partition_right(arr, a, low, high);
		pivot_q = partition_left(arr, b, low, pivot_t);
		fuzzsort_recurion(arr, low, pivot_q - 1);
		fuzzsort_recurion(arr, pivot_t + 1, high);
	}
}

int partition_right(struct arr_list* arr, int a, int low, int high)
{
	int j = low - 1;
	for (int i = low; i < high - 1; i++)
		if (arr[i].a <= a)
		{
			j++;
			swap(arr + j, arr + i);
		}
	swap(arr + j + 1, arr + high);
	return j + 1;
}

int partition_left(struct arr_list* arr, int b, int low, int high)
{
	int j = low - 1;
	for (int i = low; i < high - 1; i++)
		if (arr[i].a < b)
		{
			j++;
			swap(arr + j, arr + i);
		}
	swap(arr + j + 1, arr + high);
	return j + 1;
}

void find_intersection(struct arr_list* arr, int low, int high, int& a, int& b)
{
	int rand_index;
	rand_index = low + (rand() % (high - low));
	swap(arr + rand_index, arr + high);

	a = arr[high].a;
	b = arr[high].b;

	int j = low;
	for (int i = low; i < high - 1; i++)
		if ((arr[i].a <= b) && (arr[i].b >= a))
		{
			if (arr[i].a > a)
				a = arr[i].a;
			if (arr[i].b < b)
				b = arr[i].b;
		}
}