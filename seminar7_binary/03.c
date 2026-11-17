#include <stdio.h>
#include <string.h>

int main() {
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};

    char* p1 = (char*)a;
    printf("(a) %s", p1);

    union {
        int a[4];
        char str[16];
    } u;
    memcpy(u.a, a, sizeof(a));
    printf("(b) %s", u.str);

    char str[17];
    memcpy(str, a, sizeof(a));
    str[16] = '\0';
    printf("(c) %s", str);

    return 0;
}