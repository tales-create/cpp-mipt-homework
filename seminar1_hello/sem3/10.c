#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int x = 0, y = 0;
    char dir[20];
    int dist;

    for (int i = 0; i < n; ++i) {
        if (scanf("%s %d", dir, &dist) == 2) {
            if (strcmp(dir, "North") == 0) y += dist;
            else if (strcmp(dir, "South") == 0) y -= dist;
            else if (strcmp(dir, "East") == 0) x += dist;
            else if (strcmp(dir, "West") == 0) x -= dist;
        }
    }

    printf("%d %d\n", x, y);
    return 0;
}