#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 14

int * find_max_crossing_subarray (int * arr, int start, int middle, int end);
int * find_maximum_subarray (int * arr, int start, int end);
int * find_maximum_subarray_polynomial (int * arr, int start, int end);

int main()
{
    int arr [SIZE] = {-1, -1, -3, -25, 20, 3, 16, -23, -18, -20, -7, -12, -5, -22};
    int * arr_output;

    arr_output = (int *) malloc (3 * sizeof (int));
    
    arr_output = find_maximum_subarray (arr, 0, SIZE - 1);
    for (int i = 0; i < 3; i++)
        printf ("%d\n", arr_output [i]);
    

    return 0;
}



int * find_max_crossing_subarray (int * arr, int start, int middle, int end)
{
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;
    int * arr_bufer;
    arr_bufer = (int *) malloc (3 * sizeof (int));
    
    for (int i = middle; i >= start; i--)
    {
        sum += arr [i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = 0;
    for (int i = middle + 1; i <= end; i++)
    {
        sum += arr [i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    arr_bufer [0] = max_left;
    arr_bufer [1] = max_right;
    arr_bufer [2] = left_sum + right_sum;
    
    return arr_bufer;
}

int * find_maximum_subarray (int * arr, int start, int end)
{
    int * arr_return;
    int * arr_left;
    int * arr_right;
    int * arr_cross;
    int middle;
    
    arr_return = (int *) malloc (3 * sizeof (int));
    arr_left = (int *) malloc (3 * sizeof (int));
    arr_right = (int *) malloc (3 * sizeof (int));
    arr_cross = (int *) malloc (3 * sizeof (int));
    
    if (start == end)
    {
        arr_return [0] = start;
        arr_return [1] = end;
        arr_return [2] = arr [start];
        return arr_return;
    }
    else if ((end - start) < 15)
    {
        arr_return = find_maximum_subarray_polynomial (arr, start, end);
        return arr_return;
    }
    else
    {
        middle = (start + end) / 2;
        
        arr_left = find_maximum_subarray (arr, start, middle);
        arr_right = find_maximum_subarray (arr, middle + 1, end);
        arr_cross = find_max_crossing_subarray (arr, start, middle, end);
        
        if ((arr_left [2] >= arr_right [2]) && (arr_left [2] >= arr_cross [2]))
            return arr_left;
        else if ((arr_right [2] >= arr_left [2]) && (arr_right [2] >= arr_cross [2]))
            return arr_right;
        else
            return arr_cross;
    }
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
    
    arr_return [0] = save_i;
    arr_return [1] = save_j;
    arr_return [2] = sum_bufer;
    return arr_return;
}