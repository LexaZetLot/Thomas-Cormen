#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void marge_sort (int * arr, int start, int end);
void merge (int * arr, int first, int last);

int main (void)
{
    int arr [SIZE] = {7, 6, 5, 4, 3};
    
    marge_sort (arr, 0, 4);
    
    for (int i = 0; i < SIZE; i++)
        printf ("%d\n", arr [i]);
    
    return 0;
}

void marge_sort (int * arr, int start, int end)
{
    if (start < end)
    {
        marge_sort (arr, start, (start + end) / 2);
        marge_sort (arr, (start + end) / 2 + 1, end);
        for (int i = 0; i < SIZE; i++)
            printf ("%d\n", arr [i]);
        getchar ();
        
        merge (arr, start, end);
    }
}

void merge (int * arr, int first, int last)
{
    int left_interaction, right_intrator, middle;
    int * arr_bufer;
    
    arr_bufer = (int *) malloc ((last - first + 1) * sizeof (int));
    
    middle = (first + last) / 2;
    left_interaction = first;
    right_intrator = middle + 1;
    
    for (int i = first; i < last; i++)
    {
        if ((left_interaction <= middle) && ((right_intrator > last) || (arr [left_interaction] < arr [right_intrator])))
        {
            *(arr_bufer + i - first) = arr [left_interaction];
            left_interaction++;
            //printf ("*%d*\n", arr_bufer [i]);
        }
        else
        {
            *(arr_bufer + i - first) = arr [right_intrator];
            right_intrator++;
            //printf ("**%d**\n", arr_bufer [i]);
        }
    }
    
    for (int i = 0; i <= last; i++)
        arr [i] = * (arr_bufer + i - first);
}