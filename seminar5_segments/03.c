#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char* result = (char*)malloc((len_a + len_b + 1) * sizeof(char));
    strcpy(result, a);
    strcat(result, b);
    return result;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    char* res = concat(str1, str2);
    printf("%s\n", res);
    free(res);
    return 0;
}