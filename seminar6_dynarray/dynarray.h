#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

typedef struct dynarray {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

void init(Dynarray* pd, size_t n);
int get(const Dynarray* pd, size_t i);
void set(Dynarray* pd, size_t i, int value);
void reserve(Dynarray* pd, size_t new_capacity);
void push_back(Dynarray* pd, int value);
int pop_back(Dynarray* pd);
void resize(Dynarray* pd, size_t new_size);
void shrink_to_fit(Dynarray* pd);
Dynarray shallow_copy(Dynarray* pd);
Dynarray deep_copy(const Dynarray* pd);
void print(const Dynarray* pd);
void destroy(Dynarray* pd);

#endif