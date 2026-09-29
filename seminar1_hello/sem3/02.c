#include <stdio.h>

int main(void) {
    for (int i = 32; i <= 126; ++i) {
        printf("Symbol = %c, Code = %d\n", i, i);
    }
    return 0;
}