#include <stdio.h>
#include <ctype.h>

void encrypt(char *str, int k) {
    k = (k % 26 + 26) % 26;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isupper((unsigned char)str[i])) {
            str[i] = 'A' + (str[i] - 'A' + k) % 26;
        } else if (islower((unsigned char)str[i])) {
            str[i] = 'a' + (str[i] - 'a' + k) % 26;
        }
    }
}