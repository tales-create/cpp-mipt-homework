#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** arr = (char**)malloc(4 * sizeof(char*));
    arr[0] = (char*)malloc(4 * sizeof(char)); strcpy(arr[0], "Cat");
    arr[1] = (char*)malloc(6 * sizeof(char)); strcpy(arr[1], "Mouse");
    arr[2] = (char*)malloc(9 * sizeof(char)); strcpy(arr[2], "Elephant");
    arr[3] = NULL;
    return arr;
}

void print_strings(const char** string_array) {
    for (int i = 0; string_array[i] != NULL; ++i) {
        printf("%s\n", string_array[i]);
    }
}

size_t* get_sizes(const char** string_array) {
    size_t count = 0;
    while (string_array[count] != NULL) {
        count++;
    }
    size_t* sizes = (size_t*)malloc(count * sizeof(size_t));
    for (size_t i = 0; i < count; ++i) {
        sizes[i] = strlen(string_array[i]);
    }
    return sizes;
}

void destroy_strings(char*** p_string_array) {
    if (p_string_array == NULL || *p_string_array == NULL) return;
    char** arr = *p_string_array;
    for (int i = 0; arr[i] != NULL; ++i) {
        free(arr[i]);
    }
    free(arr);
    *p_string_array = NULL;
}

void sort_strings(char** words) {
    size_t count = 0;
    while (words[count] != NULL) {
        count++;
    }
    for (size_t i = 0; i < count; i++) {
        for (size_t j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    char** p = get_test_strings();
    print_strings(p);
    size_t* sizes = get_sizes(const_cast<const char**>(p)); // в Си приводится автоматически
    free(sizes);
    sort_strings(p);
    destroy_strings(&p);
    return 0;
}