#include <stdio.h>

#define WIDTH 600
#define HEIGHT 400
#define CX (WIDTH / 2)
#define CY (HEIGHT / 2)
#define RADIUS 120

int main() {
    FILE *f = fopen("flag.ppm", "wb"); 
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int dx = x - CX;
            int dy = y - CY;
            
            if (dx * dx + dy * dy <= RADIUS * RADIUS) {
                unsigned char red[3] = {190, 0, 41};
                fwrite(red, 1, 3, f);
            } else {
                unsigned char white[3] = {255, 255, 255};
                fwrite(white, 1, 3, f);
            }
        }
    }
    
    fclose(f);
    return 0;
}