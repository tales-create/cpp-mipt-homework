#include <stdio.h>
#include <math.h>

#define W 500
#define H 500

typedef struct { unsigned char r, g, b; } Color;

int main() {
    Color img[W * H];
    double k = 255.0;

    for (int py = 0; py < H; py++) {
        for (int px = 0; px < W; px++) {
            double x = (px - 250.0) / 250.0;
            double y = (250.0 - py) / 250.0;
            
            double val = k * fabs(x * y);
            
            if (val > 255.0) val = 255.0;
            if (val < 0.0) val = 0.0;
            
            unsigned char c = (unsigned char)val;
            img[py * W + px] = (Color){c, c, c};
        }
    }

    FILE* f = fopen("func.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", W, H);
    fwrite(img, sizeof(Color), W * H, f);
    fclose(f);
    return 0;
}