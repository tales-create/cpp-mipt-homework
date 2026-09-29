#include <stdio.h>
#include <string.h>

int main(void) {
    char c;
    if (scanf(" %c", &c) != 1) return 0;

    const char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";

    if (strchr(letters, c) != NULL) {
        printf("Letter\n");
    } else if (strchr(digits, c) != NULL) {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }
    return 0;
}