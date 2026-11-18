#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Color;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");

    char format[3];
    int w, h, maxval;
    fscanf(f, "%2s %d %d %d\n", format, &w, &h, &maxval);

    Color* img = (Color*)malloc(w * h * sizeof(Color));
    fread(img, sizeof(Color), w * h, f);
    fclose(f);

    for (int i = 0; i < w * h; i++) {
        unsigned char gray = (unsigned char)(0.299 * img[i].r + 0.587 * img[i].g + 0.114 * img[i].b);
        img[i].r = gray;
        img[i].g = gray;
        img[i].b = gray;
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n255\n", w, h);
    fwrite(img, sizeof(Color), w * h, out);
    fclose(out);
    free(img);
    return 0;
}
