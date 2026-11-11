#include <stdio.h>

int main(void) {

#ifndef COUNT
    printf("No count!\n");

#elif COUNT > 100
    printf("Count is too large!\n");

#else

#ifdef REVERSE
    for (int i = COUNT; i >= 1; --i) {
        printf("%d ", i);
    }
#else
    for (int i = 1; i <= COUNT; ++i) {
        printf("%d ", i);
    }
#endif

    printf("\n");

#endif

    return 0;
}