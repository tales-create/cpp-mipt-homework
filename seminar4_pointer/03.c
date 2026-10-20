#include <stdio.h>

void cube(float* px) {
    if (px != NULL) {
        *px = (*px) * (*px) * (*px);
    }
}

//int main(void) {
    float x = 3.0f;
    cube(&x);
    printf("%f\n", x);
    return 0;
}