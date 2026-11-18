#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define W 800
#define H 800

typedef struct {
    unsigned char r, g, b;
} Color;

void draw_line(Color* img, int x0, int y0, int x1, int y1, Color c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        if (x0 >= 0 && x0 < W && y0 >= 0 && y0 < H) {
            img[y0 * W + x0] = c;
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void draw_tree(Color* img, int x, int y, double angle, double length, int depth) {
    if (depth == 0 || length < 2) return;

    int x2 = x + (int)(length * cos(angle));
    int y2 = y - (int)(length * sin(angle));

    draw_line(img, x, y, x2, y2, (Color){0, 0, 0});

    draw_tree(img, x2, y2, angle + M_PI / 6, length * 0.7, depth - 1);
    draw_tree(img, x2, y2, angle - M_PI / 6, length * 0.7, depth - 1);
}

int main() {
    Color* img = (Color*)malloc(W * H * sizeof(Color));
    Color white = {255, 255, 255};
    for (int i = 0; i < W * H; i++) {
        img[i] = white;
    }

    draw_tree(img, W / 2, H - 50, M_PI / 2, 200.0, 9);

    FILE* f = fopen("tree.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", W, H);
    fwrite(img, sizeof(Color), W * H, f);
    fclose(f);
    
    free(img);
    return 0;
}
