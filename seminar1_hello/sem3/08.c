#include <stdio.h>

int main(void) {
    int a;
    if (scanf("%i", &a) == 1) {
        printf("a=%i\n", a);
    }

    char str[100];

    if (scanf(" %[^\n]", str) == 1) {
        printf("str=%s\n", str);
    }

    return 0;
}