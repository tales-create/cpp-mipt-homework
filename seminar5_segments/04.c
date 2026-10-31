#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroy_strings(char*** p_string_array);

char** get_test_strings(void) {
    const char* words[] = {"Cat", "Mouse", "Elephant"};

    char** arr = calloc(4, sizeof(char*));
    if (arr == NULL) return NULL;

    for (size_t i = 0; i < 3; ++i) {
        arr[i] = malloc(strlen(words[i]) + 1);

        if (arr[i] == NULL) {
            destroy_strings(&arr);
            return NULL;
        }

        strcpy(arr[i], words[i]);
    }

    return arr;
}

void print_strings(const char** string_array) {
    if (string_array == NULL) return;

    for (size_t i = 0; string_array[i] != NULL; ++i) {
        printf("%s\n", string_array[i]);
    }
}

size_t* get_sizes(const char** string_array) {
    if (string_array == NULL) return NULL;

    size_t count = 0;

    while (string_array[count] != NULL) {
        ++count;
    }

    size_t* sizes = malloc((count ? count : 1) * sizeof(size_t));
    if (sizes == NULL) return NULL;

    for (size_t i = 0; i < count; ++i) {
        sizes[i] = strlen(string_array[i]);
    }

    return sizes;
}

void destroy_strings(char*** p_string_array) {
    if (p_string_array == NULL || *p_string_array == NULL)
        return;

    char** arr = *p_string_array;

    for (size_t i = 0; arr[i] != NULL; ++i) {
        free(arr[i]);
    }

    free(arr);
    *p_string_array = NULL;
}

void sort_strings(char** words) {
    if (words == NULL) return;

    size_t count = 0;

    while (words[count] != NULL) {
        ++count;
    }

    for (size_t i = 0; i < count; ++i) {
        for (size_t j = i + 1; j < count; ++j) {
            if (strcmp(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

static int add_line(char*** lines, size_t* count,
                    const char* buffer, size_t len) {

    char* line = malloc(len + 1);
    if (line == NULL) return 0;

    memcpy(line, buffer, len);
    line[len] = '\0';

    char** new_lines =
        realloc(*lines, (*count + 2) * sizeof(char*));

    if (new_lines == NULL) {
        free(line);
        return 0;
    }

    *lines = new_lines;
    (*lines)[(*count)++] = line;
    (*lines)[*count] = NULL;

    return 1;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return NULL;

    char** lines = malloc(sizeof(char*));

    if (lines == NULL) {
        fclose(file);
        return NULL;
    }

    lines[0] = NULL;

    size_t count = 0;
    size_t length = 0;
    size_t capacity = 128;

    char* buffer = malloc(capacity);

    if (buffer == NULL) {
        destroy_strings(&lines);
        fclose(file);
        return NULL;
    }

    int ch;
    int ok = 1;
    int last = '\n';

    while ((ch = fgetc(file)) != EOF) {
        last = ch;

        if (ch == '\n') {
            size_t len = length;

            if (len > 0 && buffer[len - 1] == '\r') {
                --len;
            }

            if (!add_line(&lines, &count, buffer, len)) {
                ok = 0;
                break;
            }

            length = 0;
        } else {
            if (length == capacity) {
                if (capacity > (size_t)-1 / 2) {
                    ok = 0;
                    break;
                }

                size_t new_capacity = capacity * 2;
                char* new_buffer = realloc(buffer, new_capacity);

                if (new_buffer == NULL) {
                    ok = 0;
                    break;
                }

                buffer = new_buffer;
                capacity = new_capacity;
            }

            buffer[length++] = (char)ch;
        }
    }

    if (ferror(file)) {
        ok = 0;
    }

    if (ok && last != '\n') {
        size_t len = length;

        if (len > 0 && buffer[len - 1] == '\r') {
            --len;
        }

        if (!add_line(&lines, &count, buffer, len)) {
            ok = 0;
        }
    }

    free(buffer);

    if (fclose(file) != 0) {
        ok = 0;
    }

    if (!ok) {
        destroy_strings(&lines);
        return NULL;
    }

    return lines;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    char** lines = load_lines(argv[1]);

    if (lines == NULL) {
        fprintf(stderr, "Cannot read %s\n", argv[1]);
        return 1;
    }

    sort_strings(lines);

    FILE* out = fopen(argv[2], "wb");

    if (out == NULL) {
        fprintf(stderr, "Cannot open %s\n", argv[2]);
        destroy_strings(&lines);
        return 1;
    }

    int ok = 1;

    for (size_t i = 0; lines[i] != NULL; ++i) {
        if (fprintf(out, "%s\n", lines[i]) < 0) {
            ok = 0;
            break;
        }
    }

    if (fclose(out) != 0) {
        ok = 0;
    }

    destroy_strings(&lines);

    if (!ok) {
        fprintf(stderr, "Cannot write output file\n");
        return 1;
    }

    return 0;
}
