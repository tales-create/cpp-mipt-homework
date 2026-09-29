#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;

    char *word = argv[1];
    int count = atoi(argv[2]);

    for (int i = 0; i < count; ++i) {
        printf("%s%s", word, (i == count - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}