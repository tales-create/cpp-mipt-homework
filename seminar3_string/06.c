#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrom(const char *str) {
    size_t len = strlen(str);
    if (len == 0) return true;

    size_t left = 0;
    size_t right = len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(void) {
    char str[1000];
    while (scanf("%999s", str) == 1) {
        if (is_palindrom(str)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}