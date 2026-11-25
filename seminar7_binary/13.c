#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned char r, g, b; } Color;

int main(int argc, char** argv) {
    if (argc != 2) return 1;

    FILE* f = fopen(argv[1], "rb");
    
    char format[3];
    int w, h, maxval;
    fscanf(f, "%2s %d %d %d\n", format, &w, &h, &maxval);

    Color* img = (Color*)malloc(w * h * sizeof(Color));
    fread(img, sizeof(Color), w * h, f);
    fclose(f);

    for (int i = 0; i < w * h; i++) {
        int r = img[i].r;
        int g = img[i].g;
        int b = img[i].b;
        
        int new_r = (int)(0.393 * r + 0.769 * g + 0.189 * b);
        int new_g = (int)(0.349 * r + 0.686 * g + 0.168 * b);
        int new_b = (int)(0.272 * r + 0.534 * g + 0.131 * b);
        
        if (new_r > 255) new_r = 255;
        if (new_g > 255) new_g = 255;
        if (new_b > 255) new_b = 255;
        
        img[i].r = (unsigned char)new_r;
        img[i].g = (unsigned char)new_g;
        img[i].b = (unsigned char)new_b;
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n255\n", w, h);
    fwrite(img, sizeof(Color), w * h, out);
    fclose(out);
    free(img);
    return 0;
}
