#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING_A 2
#define SIZE_STRING_B 2
#define SIZE_COLUMN_A 2
#define SIZE_COLUMN_B 2

void square_matrix_multiply_recursive (int ** arr_a, int ** arr_b, int ** arr_c, int N);
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
    
    int ** arr_b;
    arr_b = (int**) calloc (SIZE_STRING_B, sizeof (int*));
    for (int i = 0; i < SIZE_STRING_B; i++)
        arr_b [i] = (int*) calloc (SIZE_COLUMN_B, sizeof (int));
    for (int i = 0; i < SIZE_STRING_B; i++)
        for (int j = 0; j < SIZE_COLUMN_B; j++)
            arr_b [i] [j] = i + j;
    
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


void square_matrix_multiply_recursive (int ** arr_a, int ** arr_b, int ** arr_c, int N)
{
    if (N == 1)
        **arr_c = **arr_a * **arr_b;
    else 
        arr_c [0] [0] = recursive (arr_a [0] [0], arr_b [0] [0]) + recursive (arr_a [0] [1], arr_b [1] [0]);
        arr_c [0] [1] = recursive (arr_a [0] [0], arr_b [0] [1]) + recursive (arr_a [0] [1], arr_b [1] [1]);
        arr_c [1] [0] = recursive (arr_a [1] [0], arr_b [0] [1]) + recursive (arr_a [1] [1], arr_b [1] [0]);
        arr_c [1] [1] = recursive (arr_a [1] [0], arr_b [0] [1]) + recursive (arr_a [1] [1], arr_b [1] [1]);
}

int recursive (int a, int b)
{
    return a * b;
}