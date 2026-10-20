#include <stdio.h>
#include <stdalign.h>

struct cat {
    char x;
    size_t y;
};

struct dog {
    size_t y;
    char x;
};

struct mouse {
    char x;
    char y;
    size_t z;
};

struct rat {
    char x;
    size_t z;
    char y;
};

struct fox {
    char x;
    struct mouse y;
};

int main(void) {
    printf("%zu %zu\n", sizeof(char), alignof(char));
    printf("%zu %zu\n", sizeof(int), alignof(int));
    printf("%zu %zu\n", sizeof(size_t), alignof(size_t));
    printf("%zu %zu\n", sizeof(int[10]), alignof(int[10]));
    printf("%zu %zu\n", sizeof(int*), alignof(int*));
    printf("%zu %zu\n", sizeof(struct cat), alignof(struct cat));
    printf("%zu %zu\n", sizeof(struct dog), alignof(struct dog));
    printf("%zu %zu\n", sizeof(struct mouse), alignof(struct mouse));
    printf("%zu %zu\n", sizeof(struct rat), alignof(struct rat));
    printf("%zu %zu\n", sizeof(struct fox), alignof(struct fox));

    return 0;
}