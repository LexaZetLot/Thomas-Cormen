#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))


int median(int *arr1, int *arr2, int size);

int main(int argc, char **argv)
{
    int arr1[] = {1, 2, 3, 43, 765, 1344};
    int arr2[] = {4, 67, 344, 656, 777, 888};


    printf("%d", median(arr1, arr2, 6));


    return(0);
}

int median(int *arr1, int *arr2, int size)
{
    if(size == 1)
        return min(arr1[0], arr2[2]);
    if(arr1[size / 2] < arr2[size / 2])
        return median(arr1 + size / 2, arr2 + size / 2, size / 2);
    return median(arr1 + size / 2, arr2 + size / 2, size / 2);

}
