#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING_A 3
#define SIZE_STRING_B 3
#define SIZE_COLUMN_A 3
#define SIZE_COLUMN_B 3

void square_matrix_multiply (int arr_a [SIZE_STRING_A] [SIZE_COLUMN_A], int arr_b [SIZE_STRING_B] [SIZE_COLUMN_B], int arr_c [SIZE_STRING_A] [SIZE_COLUMN_B]);

int main (void)
{
    int arr_a [SIZE_STRING_A] [SIZE_COLUMN_A] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr_b [SIZE_STRING_B] [SIZE_COLUMN_B] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr_c [SIZE_STRING_A] [SIZE_COLUMN_B];
    
    square_matrix_multiply (arr_a, arr_b, arr_c);
    
    for (int i = 0; i < SIZE_STRING_A; i++, printf ("\n"))
        for (int j = 0; j < SIZE_COLUMN_A; j++)
            printf ("%d ", arr_c [i] [j]);
    return 0;
}


void square_matrix_multiply (int arr_a [SIZE_STRING_A] [SIZE_COLUMN_A], int arr_b [SIZE_STRING_B] [SIZE_COLUMN_B], int arr_c [SIZE_STRING_A] [SIZE_COLUMN_B])
{
    if (SIZE_COLUMN_A != SIZE_STRING_B)
        exit (1);
    
    int n = SIZE_STRING_A;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr_c [i] [j] += arr_a [i] [k] * arr_b [k] [j];
    
}