#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void min_search(int* arr, int size, int& num, int& index);

int main(void)
{
	int num;
	int index;
	int* arr;
	arr = (int*)malloc(N * sizeof(int));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
		arr[i] = rand();
	printf("%d", arr[0]);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	min_search(arr, N, num, index);
	printf("\n******************\n");
	printf("%d %d", num, index);
	free(arr);
	return 0;
}

void min_search(int* arr, int size, int& num, int& index)
{
	if (size > 0)
	{
		num = arr[0];
		index = 0;
		for (int i = 1; i < size; i++)
			if (arr[i] < num)
			{
				num = arr[i];
				index = i;
			}
	}
	else
		return;
}