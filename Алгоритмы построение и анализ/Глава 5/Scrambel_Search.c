#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int scrambel_search(int* arr, int n, int search_num);
void merge_sort(int* arr, int* bufer, int size);
void merge_recursion(int* arr, int* bufer, int left, int right, int parity);
void insertion_sort(int* arr, int* bufer, int size);

int main(void)
{
    int* arr;
    int n = 10;
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i;
    printf("%d", scrambel_search(arr, n, 93));

    return 0;
}

int scrambel_search(int* arr, int n, int search_num)
{
    srand(time(NULL));
    int* bufer;
    bufer = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        bufer[i] = rand();
    merge_sort(arr, bufer, n);
    for (int i = 0; i < n; i++)
        if (arr[i] == search_num)
            return arr[i];
    return INT_MIN;
}


void merge_sort(int* arr, int* bufer, int size)
{
    int parity = 2;
    size % 2 == 0 ? parity = 1 : parity;
    merge_recursion(arr, bufer, 0, size - 1, parity);
}

void merge_recursion(int* arr, int* bufer, int left, int right, int parity)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        if ((middle - left) > 7)
            merge_recursion(arr, bufer, left, middle, parity);
        else
            insertion_sort(arr + left, bufer + left, middle - left + 1);

        if ((right - (middle + 1)) > 7)
            merge_recursion(arr, bufer, middle, right, parity);
        else
            insertion_sort(arr + middle, bufer + middle, right - middle + 1);
    }
}

void insertion_sort(int* arr, int* bufer, int size)
{
    int i;
    int j;
    int key;
    int key_bufer;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        key_bufer = bufer[i];
        j = i - 1;
        while (bufer[j] > key_bufer)
        {
            arr[j + 1] = arr[j];
            bufer[j + 1] = bufer[j];
            --j;
        }
        arr[j + 1] = key;
        bufer[j + 1] = key_bufer;
    }
}