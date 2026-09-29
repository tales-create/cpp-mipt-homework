#include <stdio.h>

int main(void) {
    char c;
    long long sum = 0;

    while ((c = getchar()) != EOF && c != '\n' && c != '\r') {
        if (c >= '0' && c <= '9') {
            sum += (c - '0');
        }
    }

    printf("%lld\n", sum);
    return 0;
}