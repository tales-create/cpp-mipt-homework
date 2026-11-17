#include <stdio.h>
#include <string.h>

int main() {
    unsigned char a[16] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
                           0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

    printf("Hex: ");
    for (int i = 0; i < 16; i++) printf("%02X ", a[i]);
    printf("\n");

    printf("Dec: ");
    for (int i = 0; i < 16; i++) printf("%d ", a[i]);
    printf("\n");

    for (int i = 0; i < 16; i++) {
        unsigned char c = a[i];
        printf("Index: %02d Hex: 0x%02X ASCII: %c\n", i, c,
               (c >= 32 && c <= 126) ? c : '.');
    }

    a[5] = 0xE5;
    printf("a[5]=0xE5: ");
    for (int i = 0; i < 16; i++) printf("%02X ", a[i]);
    printf("\n");

    memmove(&a[3], &a[0], 7);
    printf("memmove: ");
    for (int i = 0; i < 16; i++) printf("%02X ", a[i]);
    printf("\n");

    memcpy(&a[0], &a[11], 5);
    printf("memcpy: ");
    for (int i = 0; i < 16; i++) printf("%02X ", a[i]);
    printf("\n");

    memset(&a[5], 0, 6);
    printf("memset: ");
    for (int i = 0; i < 16; i++) printf("%02X ", a[i]);
    printf("\n");

    return 0;
}