#include <stdio.h>
#define SIZE 5

void merge_sort (int * arr, int size);
void merge_recursion (int * arr, int left, int right);
void merge (int * arr, int left, int middle, int right);

int inverson = 0;

int main (void)
{
    int arr [SIZE] = {4, 1, 2, 3, 0};
    
    merge_sort (arr, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf ("%d ", arr [i]);
    
    printf ("\n%d", inverson);
    
    return 0;
}

void merge_sort (int * arr, int size)
{
    merge_recursion (arr, 0, size - 1);
}

void merge_recursion (int * arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        
        merge_recursion (arr, left, middle);
        merge_recursion (arr, middle + 1, right);
        merge (arr, left, middle, right);
    }
}

void merge (int * arr, int left, int middle, int right)
{
    int left_size = middle - left + 1;
    int right_size = right - middle;
    int arr_left [left_size];
    int arr_right [right_size];
    int i, j, k;
    
    for (int i = 0; i < left_size; i++)
        arr_left [i] = arr [left + i];
    for (int i = 0; i < right_size; i++)
        arr_right [i] = arr [middle + 1 + i];
    
    for (i = 0, j = 0 , k = left; k <= right; k++)
    {
        if (i < j && arr_left [i] > arr_right [j])
            inverson++;
        
        if ((i < left_size) && (j >= right_size || arr_left [i] <= arr_right [j]))
        {
            arr [k] = arr_left [i];
            i++;
        }
        else
        {
            arr [k] = arr_right [j];
            j++;
        }
    }
}