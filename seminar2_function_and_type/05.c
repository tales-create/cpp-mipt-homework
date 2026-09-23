#include <stdio.h>

void print_binary(int n)
{
    if (n > 1)
    {
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}

int main()
{
    print_binary(6);
    printf("\n");

    print_binary(128);
    printf("\n");

    print_binary(4823564);
    printf("\n");

    print_binary(0);
    printf("\n");

    return 0;
}