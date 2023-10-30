#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int* arr;
	int n = 1000;
	int num = 0;
	int serch = 983;
	srand(time(NULL));

	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < 1000; i++)
		arr[i] = i;

	while (arr[num] != serch)
		num = rand() % n;

	printf("%d", num);

	return 0;
}