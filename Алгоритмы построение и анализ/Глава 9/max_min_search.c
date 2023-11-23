#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void max_min_search(int* arr, int size, int& max_num, int& max_index, int& min_num, int& min_index);
void max_min(int x, int y, int index, int& max, int& min, int& indexX, int& indexY);

int main(void)
{
	int max_num;
	int max_index;
	int min_num;
	int min_index;
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
		arr[i] = rand();
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	max_min_search(arr, N, max_num, max_index, min_num, min_index);
	printf("\n******************\n");
	printf("%d %d\n", max_num, max_index);
	printf("%d %d", min_num, min_index);
	free(arr);
	return 0;
}

void max_min(int x, int y, int index, int& max, int& min, int& indexX, int& indexY)
{
	if (x > y)
	{
		indexX = index;
		indexY = index + 1;
		max = x;
		min = y;
	}
	else
	{
		indexY = index;
		indexX = index + 1;
		min = x;
		max = y;
	}
}

void max_min_search(int* arr, int size, int& max_num, int& max_index, int& min_num, int& min_index)
{
	if (size > 0)
	{
		int search;
		if ((size % 2) == 0)
			search = 0;
		else
			search = 1;

		int max, min;
		int indexX, indexY;
		max_num = arr[0];
		max_index = 0;
		min_num = arr[0];
		min_index = 0;
		for (int i = search; i < size - 1; i += 2)
		{
			max_min(arr[i], arr[i + 1], i, max, min, indexX, indexY);
			if (max_num < max)
			{
				max_num = max;
				max_index = indexX;
			}
			if (min_num > min)
			{
				min_num = min;
				min_index = indexY;
			}
		}
	}
	else
		return;
}