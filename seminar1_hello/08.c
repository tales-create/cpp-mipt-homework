#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    int start = ((a + c - 1) / c) * c;

    for (int i = start; i <= b; i += c)
    {
        if (i == start)
            printf("%i", i);
        else
            printf(" %i", i);
    }
    printf("\n");
}