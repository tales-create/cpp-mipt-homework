#include <stdio.h>

long long trib(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long t0 = 0;
    long long t1 = 0;
    long long t2 = 1;
    long long current = 0;

    for (int i = 3; i <= n; ++i)
    {
        current = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = current;
    }

    return current;
}

int main()
{
    printf("%lld\n", trib(1));
    printf("%lld\n", trib(5));
    printf("%lld\n", trib(20));
    printf("%lld\n", trib(35));
    printf("%lld\n", trib(38));

    return 0;
}