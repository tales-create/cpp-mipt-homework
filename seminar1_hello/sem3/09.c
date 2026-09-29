#include <stdio.h>
#include <string.h>

void trim_after_first_space(char str[]) {
    char *space = strchr(str, ' ');
    if (space != NULL) {
        *space = '\0';
    }
}

int main(void) {
    char a[] = "Cats and Dogs";
    printf("%s\n", a);
    trim_after_first_space(a);
    printf("%s\n", a);
    return 0;
}