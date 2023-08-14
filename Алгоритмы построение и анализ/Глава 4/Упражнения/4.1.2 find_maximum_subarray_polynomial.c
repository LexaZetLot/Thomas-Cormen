#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 17

int * find_maximum_subarray_polynomial (int * arr, int start, int end);

int main()
{
    int arr [SIZE] = {-1, -1, -3, -25, 20, 3, 16, -23, -18, -20, -7, -12, -5, -22, -15, -4, 7};
    int * arr_output;

    arr_output = (int *) malloc (3 * sizeof (int));
    arr_output = find_maximum_subarray_polynomial (arr, 0, SIZE - 1);

    for (int i = 0; i < 3; i++)
        printf ("%d\n", arr_output [i]);

    return 0;
}

int * find_maximum_subarray_polynomial (int * arr, int start, int end)
{
    int sum_bufer = INT_MIN;
    int sum = 0;
    int save_i, save_j;
    int * arr_return;
    
    arr_return = (int *) malloc (3 * sizeof (int));
    
    for (int i = 0; i <= end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            sum += arr [j];
            if (sum_bufer < sum)
            {
                sum_bufer = sum;
                save_i = i + 1;
                save_j = j;
            }
        }
        sum = 0;
    }
    
    arr_return [0] = sum_bufer;
    arr_return [1] = save_i;
    arr_return [2] = save_j;
    
    return arr_return;
}