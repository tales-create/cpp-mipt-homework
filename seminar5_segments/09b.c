#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000000

int main() {
    getchar();
    printf("Allocating memory in heap\n");
    char* data = (char*)malloc(SIZE * sizeof(char));
    if (data == NULL) return 1;
    getchar();
    printf("Setting first char\n");
    data[0] = 'A';
    getchar();
    printf("Setting last char\n");
    data[SIZE - 1] = 'B';
    getchar();
    free(data);
    return 0;
}