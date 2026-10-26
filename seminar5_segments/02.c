#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n) {
    float* arr = (float*)malloc(n * sizeof(float));
    float current = a;
    for (int i = 0; i < n; ++i) {
        arr[i] = current;
        current *= r;
    }
    return arr;
}

int main() {
    int n = 10;
    float* powers_of_three = get_geometric_progression(1.0f, 3.0f, n);
    for (int i = 0; i < n; ++i) {
        printf("%.0f ", powers_of_three[i]);
    }
    printf("\n");
    free(powers_of_three);
    return 0;
}