#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[1000], s2[1000];
    if (scanf("%999s %999s", s1, s2) != 2) return 0;

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t max_len;

    if (len1 > len2) {
        max_len = len1;
    } else {
        max_len = len2;
    }

    for (size_t i = 0; i < max_len; ++i) {
        if (i < len1) putchar(s1[i]);
        if (i < len2) putchar(s2[i]);
    }
    putchar('\n');

    return 0;
}