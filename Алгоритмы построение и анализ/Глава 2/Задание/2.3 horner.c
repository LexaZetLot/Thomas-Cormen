#include <stdio.h>
#define SIZE 4

int horner (int * arr, int size, int x);

int main (void)
{
    int arr [SIZE] = {6, -8, 9, 10};
    int x = 15;
    
    printf ("%d", horner (arr, SIZE, x));
    
    return 0;
}

int horner(int * arr, int size, int x)
{
    int result = arr [0];
    
    for (int i = 0; i < size; i++)
        result = result*x + arr [i];
    
    return result;
}