#define SIZE 10

int binary_search (int * arr, int left, int right, int x);
void insertion_sort (int * arr, int size);

int main (void)
{
    int arr [SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    insertion_sort (arr, SIZE);
    
    return 0;
}

int binary_search (int * arr, int left, int right, int x)
{
    int middle = left + (right - left) / 2;

    if (left == right)
        return 0;
        
    if (left != right && left > right )
        return -1;
        
    if (arr [middle] == x)
        return middle;
    else if (arr [middle] > x)
        return binary_search (arr, left, middle - 1, x);
    else 
        return binary_search (arr, middle + 1, right, x);

}

void insertion_sort (int * arr, int size)
{
    int i;
    int j;
    int key;
    int loc;
    
    for (i = 1; i < size; i++)
    {
        key = arr [i];
        j = i - 1;
        
        loc = binary_search (arr, 0, j, key);
        while (j >= loc)
        {
            arr [j + 1] = arr [j];
            --j;
        }
        arr [j + 1] = key;
    }
}