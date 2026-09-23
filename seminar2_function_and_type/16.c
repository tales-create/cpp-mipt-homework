#include <stdio.h>

double pi(int n)
{
    double sum = 0.0;
    double sign = 1.0;

    for (int i = 1; i <= n; ++i)
    {
        double term = sign / (2.0 * i - 1.0);
        sum += term;
        sign = -sign;
    }

    return 4.0 * sum;
}

int main()
{
    int n;
    if (scanf("%d", &n) == 1)
    {
        printf("%.6f\n", pi(n));
    }
    return 0;
}