#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    
    printf("%ld\n", size);

    fclose(f);
    return 0;
}