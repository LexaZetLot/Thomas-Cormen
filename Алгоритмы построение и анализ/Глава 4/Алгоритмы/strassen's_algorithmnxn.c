#include <stdio.h>
#include <stdlib.h>

#define SIZE_MATRIX 8

void sum_matrix(int* a, int* b, int* c, int N, int sub_size);
void sum_matrix_only_subarry(int* a, int* b, int* c, int N, int sub_size);
void sub_matrix(int* a, int* b, int* c, int N, int sub_size);
void sub_matrix_only_subarry(int* a, int* b, int* c, int N, int sub_size);
void recording_subarry_B_M(int* a, int* b, int N, int sub_size);
void recording_subarry_M_B(int* a, int* b, int N, int sub_size);
void strassen(int* arr_a, int* arr_b, int* arr_c, int N);

int main()
{
    int* arr_a = (int*)calloc(SIZE_MATRIX * SIZE_MATRIX, sizeof(int));
    for (int i = 0; i < SIZE_MATRIX; i++)
        for (int j = 0; j < SIZE_MATRIX; j++)
            arr_a[i * SIZE_MATRIX + j] = i + j;
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
            printf("%d ", arr_a[i * SIZE_MATRIX + j]);
        printf("\n");
    }
    printf("******************\n");


    int* arr_b = (int*)calloc(SIZE_MATRIX * SIZE_MATRIX, sizeof(int));
    for (int i = 0; i < SIZE_MATRIX; i++)
        for (int j = 0; j < SIZE_MATRIX; j++)
            arr_b[i * SIZE_MATRIX + j] = i + j;
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
            printf("%d ", arr_b[i * SIZE_MATRIX + j]);
        printf("\n");
    }
    printf("******************\n");

    int* arr_c = (int*)calloc(SIZE_MATRIX * SIZE_MATRIX, sizeof(int));
    strassen(arr_a, arr_b, arr_c, SIZE_MATRIX);

    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
            printf("%d ", arr_c[i * SIZE_MATRIX + j]);
        printf("\n");
    }

    return 0;
}

void strassen(int* arr_a, int* arr_b, int* arr_c, int N)
{
    if (N == 1)
        (*arr_c) = (*arr_b) * (*arr_a);
    else
    {
        int subarry_N = (N / 2);
        int* D_0 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* D_1 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* D_2 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* H_0 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* H_1 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* V_0 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* V_1 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* BUFER_0 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* BUFER_1 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* BUFER_2 = (int*)calloc(subarry_N * subarry_N, sizeof(int));
        int* BUFER_3 = (int*)calloc(subarry_N * subarry_N, sizeof(int));

        //D_0                                                                                                                                                   
        sum_matrix(&(*(arr_a + (0 * N + 0))), &(*(arr_a + (subarry_N * N + subarry_N))), BUFER_0, N, subarry_N);
        sum_matrix(&(*(arr_b + (0 * N + 0))), &(*(arr_b + (subarry_N * N + subarry_N))), BUFER_1, N, subarry_N);
        strassen(BUFER_0, BUFER_1, D_0, subarry_N);

        //D_1                                                                                                                                                   
        sub_matrix(&(*(arr_a + (0 * N + subarry_N))), &(*(arr_a + (subarry_N * N + subarry_N))), BUFER_0, N, subarry_N);
        sum_matrix(&(*(arr_b + (subarry_N * N + 0))), &(*(arr_b + (subarry_N * N + subarry_N))), BUFER_1, N, subarry_N);
        strassen(BUFER_0, BUFER_1, D_1, subarry_N);

        //D_2                                                                                                                                                   
        sub_matrix(&(*(arr_a + (subarry_N * N + 0))), &(*(arr_a + (0 * N + 0))), BUFER_0, N, subarry_N);
        sum_matrix(&(*(arr_b + (0 * N + 0))), &(*(arr_b + (0 * N + subarry_N))), BUFER_1, N, subarry_N);
        strassen(BUFER_0, BUFER_1, D_2, subarry_N);

        //H_0                                                                                                                                                   
        sum_matrix(&(*(arr_a + (0 * N + 0))), &(*(arr_a + (0 * N + subarry_N))), BUFER_0, N, subarry_N);
        recording_subarry_M_B(BUFER_1, &(*(arr_b + (subarry_N * N + subarry_N))), N, subarry_N);
        strassen(BUFER_0, BUFER_1, H_0, subarry_N);

        //H_1                                                                                                                                                   
        sum_matrix(&(*(arr_a + (subarry_N * N + 0))), &(*(arr_a + (subarry_N * N + subarry_N))), BUFER_0, N, subarry_N);
        recording_subarry_M_B(BUFER_1, &(*(arr_b + (0 * N + 0))), N, subarry_N);
        strassen(BUFER_0, BUFER_1, H_1, subarry_N);

        //V_0                                                                                                                                                   
        sub_matrix(&(*(arr_b + (subarry_N * N + 0))), &(*(arr_b + 0 * N + 0)), BUFER_0, N, subarry_N);
        recording_subarry_M_B(BUFER_1, &(*(arr_a + (subarry_N * N + subarry_N))), N, subarry_N);
        strassen(BUFER_1, BUFER_0, V_0, subarry_N);

        //V_1                                                                                                                                                   
        sub_matrix(&(*(arr_b + (0 * N + subarry_N))), &(*(arr_b + (subarry_N * N + subarry_N))), BUFER_0, N, subarry_N);
        recording_subarry_M_B(BUFER_1, &(*(arr_a + (0 * N + 0))), N, subarry_N);
        strassen(BUFER_1, BUFER_0, V_1, subarry_N);

        //1                                                                                                                                                    
        sum_matrix_only_subarry(D_0, D_1, BUFER_1, N, subarry_N);
        sub_matrix_only_subarry(V_0, H_0, BUFER_2, N, subarry_N);
        sum_matrix_only_subarry(BUFER_1, BUFER_2, BUFER_0, N, subarry_N);

        //4                                                                                                                                                     
        sum_matrix_only_subarry(D_0, D_2, BUFER_1, N, subarry_N);
        sub_matrix_only_subarry(V_1, H_1, BUFER_2, N, subarry_N);
        sum_matrix_only_subarry(BUFER_1, BUFER_2, BUFER_3, N, subarry_N);

        //2                                                                                                                                                     
        sum_matrix_only_subarry(V_1, H_0, BUFER_1, N, subarry_N);

        //3                                                                                                                                                     
        sum_matrix_only_subarry(V_0, H_1, BUFER_2, N, subarry_N);

        recording_subarry_B_M(&(*(arr_c + (0 * N + 0))), BUFER_0, N, subarry_N);
        recording_subarry_B_M(&(*(arr_c + (0 * N + subarry_N))), BUFER_1, N, subarry_N);
        recording_subarry_B_M(&(*(arr_c + (subarry_N * N + 0))), BUFER_2, N, subarry_N);
        recording_subarry_B_M(&(*(arr_c + (subarry_N * N + subarry_N))), BUFER_3, N, subarry_N);

    }
}

void sum_matrix(int* a, int* b, int* c, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(c + (i * sub_size + j))) = (*(a + (i * N + j))) + (*(b + (i * N + j)));
}

void sub_matrix(int* a, int* b, int* c, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(c + (i * sub_size + j))) = (*(a + (i * N + j))) - (*(b + (i * N + j)));
}

void recording_subarry_B_M(int* a, int* b, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(a + (i * N + j))) = (*(b + (i * sub_size + j)));
}

void recording_subarry_M_B(int* a, int* b, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(a + (i * sub_size + j))) = (*(b + (i * N + j)));
}

void sum_matrix_only_subarry(int* a, int* b, int* c, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(c + (i * sub_size + j))) = (*(a + (i * sub_size + j))) + (*(b + (i * sub_size + j)));

}

void sub_matrix_only_subarry(int* a, int* b, int* c, int N, int sub_size)
{
    for (int i = 0; i < sub_size; i++)
        for (int j = 0; j < sub_size; j++)
            (*(c + (i * sub_size + j))) = (*(a + (i * sub_size + j))) - (*(b + (i * sub_size + j)));
}