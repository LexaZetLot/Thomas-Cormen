#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **quartile(int *arr, size_t arrlen, size_t num);

int main (void)
{
    int *arr = (int *)malloc(100 * sizeof(int));
    int **res;

    srand(time(NULL));
    for(int i = 0; i < 100; i++)
        arr[i] = rand();

    res = quartile(arr, 100, 4);

    for(int i = 0; i < 4; i++, printf("\n"))
        for(int j = 0; j < 25; j++)
            printf("%d ", res[i][j]);

    return 0;
}

int **quartile(int *arr, size_t arrlen, size_t num)
{
    int  **res;
    int i;

    if((arrlen % num) != 0)
        return NULL;

    res = (int **)malloc(num * sizeof(int *));
    for (i = 0; i < num; i++)
        res[i] = (int *)malloc(arrlen / num * sizeof(&arr));

    for(i = 0; i < num; i++)
        memcpy(res[i], arr + i * arrlen / num, arrlen / num * sizeof(&arr));

    return res;
}

