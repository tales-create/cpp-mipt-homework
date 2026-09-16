#include <stdio.h>

int sum_of_digits(int num) {
    if (num < 0) num = -num;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[10000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sum_of_digits(a[j]) > sum_of_digits(a[j + 1])) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            printf("%d", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    return 0;
}