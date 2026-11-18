#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 800
#define H 600

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

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);

    srand(time(NULL));

    Color* img = (Color*)malloc(W * H * sizeof(Color));
    Color white = {255, 255, 255};
    for (int i = 0; i < W * H; i++) {
        img[i] = white;
    }

    for (int i = 0; i < n; i++) {
        int x0 = rand() % W;
        int y0 = rand() % H;
        int x1 = rand() % W;
        int y1 = rand() % H;
        
        Color c = { (unsigned char)(rand() % 256), 
                    (unsigned char)(rand() % 256), 
                    (unsigned char)(rand() % 256) };

        draw_line(img, x0, y0, x1, y1, c);
    }

    FILE* f = fopen("randlines.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", W, H);
    fwrite(img, sizeof(Color), W * H, f);
    fclose(f);
    
    free(img);
    return 0;
}
