#define SIZE 7

void insertion_sort (int * arr, int N);

int main (void)
{
    int arr [SIZE] = {4, 7, 2, 1, 56, 93, 0};
    
    insertion_sort (arr, SIZE);

    return 0;
}


void insertion_sort (int * arr, int N)
{
    int i;
    int j;
    int key;
    
    for (i = 1; i < N; i++)
    {
        key = arr [i];
        j = i - 1;
        while (j >= 0 && arr [j] < key)
        {
            arr [j + 1] = arr [j];
            --j;
        }
        arr [j + 1] = key;
    }
}