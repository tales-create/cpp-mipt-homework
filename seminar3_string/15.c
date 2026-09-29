#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./line_extractor <input_file> <output_file> <lines>\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    int start_line = -1, end_line = -1;
    char extra[2];

    if (sscanf(argv[3], "%d:%d%1s", &start_line, &end_line, extra) == 2) {
        // Формат start:end
    } else if (sscanf(argv[3], "%d%1s", &start_line, extra) == 1) {
        end_line = start_line + 1;
    } else {
        printf("Error: Wrong lines format!\n");
        fclose(fin);
        return 1;
    }

    if (start_line <= 0 || end_line < start_line) {
        printf("Error: Wrong lines format!\n");
        fclose(fin);
        return 1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        fclose(fin);
        return 1;
    }

    char buffer[4096];
    int current_line = 1;

    while (fgets(buffer, sizeof(buffer), fin)) {
        if (current_line >= start_line && current_line < end_line) {
            fputs(buffer, fout);
        }
        current_line++;
    }

    fclose(fin);
    fclose(fout);
    return 0;
}