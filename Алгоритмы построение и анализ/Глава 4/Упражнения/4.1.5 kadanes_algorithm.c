#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 17

int * kadanes (int * arr, int start, int end);

int main()
{
    int arr [SIZE] = {-1, -1, -3, -25, 20, 3, 16, -23, -18, -20, -7, -12, -5, -22, -15, -4, 7};
    int * arr_output;
    arr_output = (int *) malloc (3 * sizeof (int));
    
    arr_output = kadanes (arr, 0, SIZE);
    for (int i = 0; i < 3; i++)
        printf ("%d ", arr_output [i]);
    
    return 0;
}

int * kadanes (int * arr, int start, int end)
{
    int max_sum = INT_MIN; 
    int max_ending_here = 0;
    int save_start_subarray, save_end_subarray;
    int bufer;
    int * arr_return;
    
    arr_return = (int *) malloc (3 * sizeof (int));
    
    for (int i = 0; i < end; i++) 
    {
        max_ending_here += arr [i];
        
        if (max_sum < max_ending_here) 
        {
            max_sum = max_ending_here;
            save_start_subarray = bufer;
            save_end_subarray = i;
        }
        if (max_ending_here < 0) 
        {
            max_ending_here = 0;
            bufer = i + 1;
        }
    }
    
    arr_return [0] = save_start_subarray;
    arr_return [1] = save_end_subarray;
    arr_return [2] = max_sum;
    
    return arr_return;
}