#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

static void* ecmalloc(size_t n) {
    void* p = malloc(n);

    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    return p;
}

void init(Dynarray* pd, size_t n) {
    pd->size = n;
    pd->capacity = n;
    pd->data = NULL;

    if (n > 0) {
        if (n > SIZE_MAX / sizeof(int)) exit(1);
        pd->data = calloc(n, sizeof(int));

        if (pd->data == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
    }
}

int get(const Dynarray* pd, size_t i) {
    assert(i < pd->size);
    return pd->data[i];
}

void set(Dynarray* pd, size_t i, int value) {
    assert(i < pd->size);
    pd->data[i] = value;
}

void reserve(Dynarray* pd, size_t new_capacity) {
    if (new_capacity <= pd->capacity) return;
    if (new_capacity > SIZE_MAX / sizeof(int)) exit(1);

    int* new_data = ecmalloc(new_capacity * sizeof(int));

    if (pd->size > 0) {
        memcpy(new_data, pd->data, pd->size * sizeof(int));
    }

    free(pd->data);

    pd->data = new_data;
    pd->capacity = new_capacity;
}

void push_back(Dynarray* pd, int value) {
    if (pd->size == pd->capacity) {
        size_t new_capacity = pd->capacity == 0 ? 1 : pd->capacity;

        if (pd->capacity != 0) {
            if (pd->capacity > SIZE_MAX / 2) exit(1);
            new_capacity *= 2;
        }

        reserve(pd, new_capacity);
    }

    pd->data[pd->size++] = value;
}

int pop_back(Dynarray* pd) {
    if (pd->size == 0) {
        fprintf(stderr, "Error: array is empty\n");
        exit(1);
    }

    return pd->data[--pd->size];
}

void resize(Dynarray* pd, size_t new_size) {
    if (new_size > pd->capacity) {
        reserve(pd, new_size);
    }

    for (size_t i = pd->size; i < new_size; ++i) {
        pd->data[i] = 0;
    }

    pd->size = new_size;
}

void shrink_to_fit(Dynarray* pd) {
    if (pd->size == pd->capacity) return;

    if (pd->size == 0) {
        free(pd->data);
        pd->data = NULL;
        pd->capacity = 0;
        return;
    }

    int* temp = realloc(pd->data, pd->size * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    pd->data = temp;
    pd->capacity = pd->size;
}

Dynarray shallow_copy(Dynarray* pd) {
    return *pd;
}

Dynarray deep_copy(const Dynarray* pd) {
    Dynarray copy;

    copy.size = pd->size;
    copy.capacity = pd->capacity;
    copy.data = NULL;

    if (copy.capacity > 0) {
        if (copy.capacity > SIZE_MAX / sizeof(int)) exit(1);

        copy.data = ecmalloc(copy.capacity * sizeof(int));

        if (copy.size > 0) {
            memcpy(copy.data, pd->data, copy.size * sizeof(int));
        }
    }

    return copy;
}

void print(const Dynarray* pd) {
    for (size_t i = 0; i < pd->size; ++i) {
        printf("%d ", pd->data[i]);
    }

    printf("\n");
}

void destroy(Dynarray* pd) {
    free(pd->data);

    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}