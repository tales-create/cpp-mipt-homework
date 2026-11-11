#include <stdio.h>

int main(void) {
#ifdef DOG
    printf("Dog!\n");
#else
    printf("No dog!\n");
#endif

    return 0;
}