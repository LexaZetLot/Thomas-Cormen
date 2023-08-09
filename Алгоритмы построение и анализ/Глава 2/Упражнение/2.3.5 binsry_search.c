#define SIZE 10

int binary_search (int * arr, int left, int right, int x);

int main (void)
{
    int arr [SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    return 0;
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