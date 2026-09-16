#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int sum[1000] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            scanf("%d", &num);
            sum[j] += num;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (j == m - 1) {
            printf("%d", sum[j]);
        } else {
            printf("%d ", sum[j]);
        }
    }
    printf("\n");

}