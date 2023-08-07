#define SIZE 7

void selection_sort (int * arr);

int main (void)
{
    int arr [SIZE] = {7, 6, 5, 4, 3, 2, 1};
    
    selection_sort (arr);

    return 0;
}

void selection_sort (int * arr)
{
    int bufer, bufer_index_j, j;
    
    for (int i = 0; i < SIZE; i++)
    {
        bufer = arr [i];
        bufer_index_j = i;
        
        for (j = i; j < SIZE; j++)
            if (bufer > arr [j])
                bufer_index_j = j;
    
        arr [i] = arr [bufer_index_j];
        arr [bufer_index_j] = bufer;
    }

}