#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (!f) {
        perror("fopen");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    if (size < 3) {
        printf("File is too small\n");
    } else {
        fseek(f, -3, SEEK_END);
        unsigned char buf[3];
        fread(buf, 1, 3, f);
        printf("Last 3 bytes: %02X %02X %02X\n", buf[0], buf[1], buf[2]);
    }

    fclose(f);
    return 0;
}