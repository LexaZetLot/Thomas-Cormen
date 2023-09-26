#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void)
{
	int best = 0;
	int bufer[SIZE];

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		bufer[i] = rand();
		if (bufer[i] > best)
		{
			best = bufer[i];
			printf("%d\n", best);
		}
	}
	return 0;
}