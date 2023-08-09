#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void merge_sort (int * arr, int size);
void merge_recursion (int * arr, int left, int right);
void merge (int * arr, int left, int middle, int right);
int binary_search (int * arr, int left, int right, int x);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main (void)
{
    int * arr;
    int arr1 [SIZE] = {2, 7, 10, 3};
    int *returnSize;
    
    arr = (int *) malloc (8);

    arr = twoSum (arr1, SIZE, 5, returnSize);
    //printf ("%d", binary_search (arr1, 0, SIZE, 10));
    for (int i = 0; i < 2; i++)
        printf ("%d", arr [i]);
    return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int bufer;
    int * result;
    int a = 2;
    returnSize = &a;

    result = (int *) malloc (* returnSize * sizeof (int));
    merge_sort (nums, numsSize);

    for (int i = 0; i < numsSize; i++)
        if ((bufer = binary_search (nums, 0, numsSize - 1, target - nums [i])) != -1)
        {
            result [0] = i;
            result [1] = bufer;
            return result;
        } 
    return NULL;
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

int binary_search (int * arr, int left, int right, int x)
{
    int middle = left + (right - left) / 2;

    if (left > right)
        return -1;

    if (arr [middle] == x)
        return middle;
    else if (arr [middle] > x)
        return binary_search (arr, left, middle - 1, x);
    else 
        return binary_search (arr, middle + 1, right, x);

}
