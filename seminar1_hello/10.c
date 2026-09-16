#include <stdio.h>

int main() {
    int a[1000];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            a[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < k; ++i) {
        if (i == k - 1) {
            printf("%d", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}