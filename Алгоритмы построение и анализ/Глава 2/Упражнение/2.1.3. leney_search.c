#define SIZE 7

int leney_search (int * arr, int N, int x);

int main (void)
{
    int arr [SIZE] = {4, 7, 2, 1, 56, 93, 0};
    
    leney_search (arr, SIZE, 4);

    return 0;
}


int leney_search (int * arr, int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (arr [i] == x)
            return i;
    }
    
    return 0;
}