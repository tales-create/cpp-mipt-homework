#include <stdio.h>

#define MAX 100

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = 0.0f;
            for (int k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(float matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%6.0f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float A[MAX][MAX] = {
        {7.0f, 7.0f, 2.0f},
        {1.0f, 8.0f, 3.0f},
        {2.0f, 1.0f, 6.0f}
    };

    float B[MAX][MAX] = {
        {5.0f, 2.0f, 9.0f},
        {-4.0f, 2.0f, 11.0f},
        {7.0f, 1.0f, -5.0f}
    };

    float C[MAX][MAX];

    multiply(A, B, C, 3);
    print_matrix(C, 3);

    return 0;
}