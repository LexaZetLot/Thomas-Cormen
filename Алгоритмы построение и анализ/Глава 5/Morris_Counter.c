#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pow_element(int a);
int rand_morris(int i);
int morris(int num);

int counter = 0;

int main(void)
{
	srand(time(NULL));
	int num;

	for (int i = 0; i < 100000000; i++)
		num = morris(i);

	printf("%d", num);

	return 0;
}

int pow_element(int a)
{
	return a * a;
}
int rand_morris(int i)
{
	return rand() % (pow_element(i + 1) - pow_element(i) + 1);
}

int morris(int num)
{
	int rand_number;
	rand_number = rand_morris(num);
	//printf("%d  %d \n", rand_number, counter);
	if (rand_number == 1)
		counter++;
	return counter;
}