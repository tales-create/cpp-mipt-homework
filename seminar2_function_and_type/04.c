#include <stdio.h>

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sum_of_digits_rec(int n)
{
    if (n < 10)
    {
        return n;
    }
    return (n % 10) + sum_of_digits_rec(n / 10);
}

int main()
{
    printf("%i\n", sum_of_digits(123));
    printf("%i\n", sum_of_digits(55955));
    printf("%i\n", sum_of_digits(4));
    printf("%i\n", sum_of_digits(0));

    printf("%i\n", sum_of_digits_rec(123));
    printf("%i\n", sum_of_digits_rec(55955));
    printf("%i\n", sum_of_digits_rec(4));
    printf("%i\n", sum_of_digits_rec(0));

    return 0;
}