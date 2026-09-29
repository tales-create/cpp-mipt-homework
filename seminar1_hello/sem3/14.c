#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt_char(int *c, int k) {
    k = (k % 26 + 26) % 26;
    if (isupper(*c)) {
        *c = 'A' + (*c - 'A' + k) % 26;
    } else if (islower(*c)) {
        *c = 'a' + (*c - 'a' + k) % 26;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) return 1;

    FILE *fin = fopen(argv[1], "r");
    if (!fin) return 1;

    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        fclose(fin);
        return 1;
    }

    int key = atoi(argv[3]);
    int c;

    while ((c = fgetc(fin)) != EOF) {
        encrypt_char(&c, key);
        fputc(c, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}