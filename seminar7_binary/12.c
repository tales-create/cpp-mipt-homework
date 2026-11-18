#include <stdio.h>
#include <stdlib.h>

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
        unsigned char tmp = img[i].r;
        img[i].r = img[i].b;
        img[i].b = tmp;
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n255\n", w, h);
    fwrite(img, sizeof(Color), w * h, out);
    fclose(out);
    free(img);
    return 0;
}
