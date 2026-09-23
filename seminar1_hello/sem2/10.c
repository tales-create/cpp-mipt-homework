#include <stdio.h>

#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = B[i][j];
        }
    }
}

void print_matrix(float matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float B[MAX][MAX] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float A[MAX][MAX] = {0};

    assign(A, B, 3);
    print_matrix(A, 3);

    return 0;
}