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

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
    float temp[MAX][MAX];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = 0.0f;
            for (int k = 0; k < n; ++k)
            {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    assign(C, temp, n);
}

void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k)
{
    float B[MAX][MAX];
    assign(B, A, n);
    assign(C, A, n);

    for (int step = 1; step < k; ++step)
    {
        multiply(A, B, C, n);
        assign(B, C, n);
    }
}

void print_matrix(float matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%.0f ", matrix[i][j]);
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

    float C[MAX][MAX];

    power(A, C, 3, 4);
    print_matrix(C, 3);

    return 0;
}