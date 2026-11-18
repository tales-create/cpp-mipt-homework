#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} Color;

int random_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c) {
    for (int y = y0 - r; y <= y0 + r; y++) {
        for (int x = x0 - r; x <= x0 + r; x++) {
            if (x >= 0 && x < width && y >= 0 && y < height) {
                int dx = x - x0;
                int dy = y - y0;
                if (dx * dx + dy * dy <= r * r) {
                    data[y * width + x] = c; 
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <n> <min_radius> <max_radius>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    srand(time(NULL));

    Color* canvas = (Color*)malloc(WIDTH * HEIGHT * sizeof(Color));

    Color white = {255, 255, 255};
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        canvas[i] = white;
    }

    for (int i = 0; i < n; i++) {
        int x0 = random_range(0, WIDTH);
        int y0 = random_range(0, HEIGHT);
        int r = random_range(a, b);
        Color c = { (unsigned char)random_range(0, 255), 
                    (unsigned char)random_range(0, 255), 
                    (unsigned char)random_range(0, 255) };

        draw_circle(canvas, WIDTH, HEIGHT, x0, y0, r, c);
    }

    FILE* f = fopen("circles.ppm", "wb");
    
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(canvas, sizeof(Color), WIDTH * HEIGHT, f);
    fclose(f);

    free(canvas);
    printf("Image saved to circles.ppm\n");

    return 0;
}
