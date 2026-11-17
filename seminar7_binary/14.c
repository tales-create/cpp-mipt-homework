#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned char r, g, b; } Color;

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <image.ppm> <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[2]);

    FILE* f = fopen(argv[1], "rb");
    if (!f) return 1;

    char format[3];
    int w, h, maxval;
    fscanf(f, "%2s %d %d %d\n", format, &w, &h, &maxval);

    Color* img = (Color*)malloc(w * h * sizeof(Color));
    Color* temp = (Color*)malloc(w * h * sizeof(Color));
    fread(img, sizeof(Color), w * h, f);
    fclose(f);

    for (int iter = 0; iter < n; iter++) {
        memcpy(temp, img, w * h * sizeof(Color));

        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                int sum_r = 0, sum_g = 0, sum_b = 0;
                
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        Color p = temp[(y + dy) * w + (x + dx)];
                        sum_r += p.r;
                        sum_g += p.g;
                        sum_b += p.b;
                    }
                }
                img[y * w + x].r = sum_r / 9;
                img[y * w + x].g = sum_g / 9;
                img[y * w + x].b = sum_b / 9;
            }
        }
    }
    free(temp);

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n255\n", w, h);
    fwrite(img, sizeof(Color), w * h, out);
    fclose(out);
    free(img);
    return 0;
}