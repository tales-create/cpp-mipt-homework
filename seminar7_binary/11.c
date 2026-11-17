#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned char r, g, b; } Color;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (!f) { perror("fopen"); return 1; }

    char format[3];
    int w, h, maxval;
    fscanf(f, "%2s %d %d %d\n", format, &w, &h, &maxval);

    if (strcmp(format, "P6") != 0) {
        printf("Only P6 format supported\n");
        fclose(f);
        return 1;
    }

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