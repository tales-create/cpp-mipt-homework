#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;
    if (scanf(" %c", &c) != 1) return 0;

    if (isalpha((unsigned char)c)) {
        printf("Letter\n");
    } else if (isdigit((unsigned char)c)) {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }
    return 0;
}