#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);

    int max = n;
    int length = 1;

    printf("%i", n);

    while (n != 1)
    {
        if (n % 2 != 0) {
            n = 3 * n + 1;
        } else
        {
            n = n / 2;
        }
        printf(" %i", n);

        if (n > max)
        {
            max = n;
        }
        length++;
    }
    printf("\nLength = %i, Max = %i\n", length, max);
}