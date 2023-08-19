#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING_A 2
#define SIZE_STRING_B 2
#define SIZE_COLUMN_A 2
#define SIZE_COLUMN_B 2

int ** square_matrix_multiply_recursive (int ** arr_a, int ** arr_b, int ** arr_c, int N);
int recursive (int a, int b);

int main (void)
{
    int ** arr_a;
    arr_a = (int**) calloc (SIZE_STRING_A, sizeof (int*));
    for (int i = 0; i < SIZE_STRING_A; i++)
        arr_a [i] = (int*) calloc (SIZE_COLUMN_A, sizeof (int));
    for (int i = 0; i < SIZE_STRING_A; i++)
        for (int j = 0; j < SIZE_COLUMN_A; j++)
            arr_a [i] [j] = i + j;
    for (int i = 0; i < SIZE_STRING_A; i++)
    {
        for (int j = 0; j < SIZE_COLUMN_B; j++)
            printf ("%d ", arr_a [i] [j]);
        printf ("\n");
    }
    
    int ** arr_b;
    arr_b = (int**) calloc (SIZE_STRING_B, sizeof (int*));
    for (int i = 0; i < SIZE_STRING_B; i++)
        arr_b [i] = (int*) calloc (SIZE_COLUMN_B, sizeof (int));
    for (int i = 0; i < SIZE_STRING_B; i++)
        for (int j = 0; j < SIZE_COLUMN_B; j++)
            arr_b [i] [j] = i + j;
    for (int i = 0; i < SIZE_STRING_A; i++)
    {
        for (int j = 0; j < SIZE_COLUMN_B; j++)
            printf ("%d ", arr_b [i] [j]);
        printf ("\n");
    }
    
    int ** arr_c;
    arr_c = (int**) calloc (SIZE_STRING_A, sizeof (int*));
    for (int i = 0; i < SIZE_STRING_B; i++)
        arr_c [i] = (int*) calloc (SIZE_COLUMN_B, sizeof (int));

    square_matrix_multiply_recursive (arr_a, arr_b, arr_c, 2);
    
    for (int i = 0; i < SIZE_STRING_A; i++)
    {
        for (int j = 0; j < SIZE_COLUMN_B; j++)
            printf ("%d ", arr_c [i] [j]);
        printf ("\n");
    }

    return 0;
}


int ** square_matrix_multiply_recursive (int ** arr_a, int ** arr_b, int ** arr_c, int N)
{
    if (N == 1)
    {
        printf ("***%d***\n", **arr_b);
        (**arr_c) += (**arr_a); //* (**arr_b);
        return arr_c;
    }
    else 
    {
        arr_c [0] [0] = (**square_matrix_multiply_recursive (&(*(arr_a + 0)) + 0, &(*(arr_b + 0)) + 0, &(*(arr_c + 0)) + 0, N / 2)) + (**square_matrix_multiply_recursive (&(*(arr_a + 0)) + 1, &(*(arr_b + 1)) + 0, &(*(arr_c + 0)) + 0, N / 2));
        printf ("%d  %p\n",  arr_c [0] [0], &(*(arr_c + 0)) + 0);
        printf ("%d  %p\n",  arr_c [1] [0], &(*(arr_c + 1)) + 0);
        printf ("%d  %p\n",  arr_c [1] [1], &(*(arr_c + 1)) + 1);
        arr_c [0] [1] = (**square_matrix_multiply_recursive (&(*(arr_a + 0)) + 0, &(*(arr_b + 0)) + 1, &(*(arr_c + 0)) + 1, N / 2)) + (**square_matrix_multiply_recursive (&(*(arr_a + 0)) + 1, (*(arr_b + 1) + 1), &(*(arr_c + 0)) + 1, N / 2));
        //arr_c [1] [0] = square_matrix_multiply_recursive (arr_a [1] [0], arr_b [0] [0], arr_c [1] [0], N / 2) + square_matrix_multiply_recursive (arr_a [1] [1], arr_b [1] [0], arr_c [1] [0], N / 2);
        //arr_c [1] [1] = square_matrix_multiply_recursive (arr_a [1] [0], arr_b [0] [0], arr_c [1] [1], N / 2) + square_matrix_multiply_recursive (arr_a [1] [1], arr_b [1] [1], arr_c [1] [1], N / 2);
    }
}

int recursive (int a, int b)
{
    return a * b;
}