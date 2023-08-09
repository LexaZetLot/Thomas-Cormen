#define SIZE 29

void merge_sort (int * arr, int size);
void merge_recursion (int * arr, int left, int right, int parity);
void insertion_sort (int * arr, int size);

int main (void)
{
    int arr [SIZE] = {28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    merge_sort (arr, SIZE);

    return 0;
}

void merge_sort (int * arr, int size)
{
    int parity = 2;
    size % 2 == 0? parity = 1: parity;
    merge_recursion (arr, 0, size - 1, parity);
}

void merge_recursion (int * arr, int left, int right, int parity)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        
        if ((middle - left) > 7)
            merge_recursion (arr, left, middle, parity);
        else 
            insertion_sort (arr + left, middle - left + 1);
        
        if ((right - (middle + 1)) > 7)
            merge_recursion (arr, middle, right, parity);
        else
            insertion_sort (arr + middle, right - middle + 1);
    }
}

void insertion_sort (int * arr, int size)
{
    int i;
    int j;
    int key;
    
    for (i = 1; i < size; i++)
    {
        key = arr [i];
        j = i - 1;
        while (arr [j] > key)
        {
            arr [j + 1] = arr [j];
            --j;
        }
        arr [j + 1] = key;
    }
}