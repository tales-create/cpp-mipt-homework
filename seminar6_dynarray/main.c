#include <stdio.h>
#include "dynarray.h"

int main(void) {
    Dynarray a;
    init(&a, 3);

    set(&a, 0, 10);
    set(&a, 1, 20);
    set(&a, 2, 30);

    print(&a);

    push_back(&a, 40);
    print(&a);

    printf("Popped: %d\n", pop_back(&a));
    print(&a);

    resize(&a, 6);
    print(&a);

    resize(&a, 2);
    print(&a);

    shrink_to_fit(&a);
    printf("Size: %zu, Capacity: %zu\n", a.size, a.capacity);

    Dynarray shallow = shallow_copy(&a);
    Dynarray deep = deep_copy(&a);

    set(&a, 0, 999);

    print(&a);
    print(&shallow);
    print(&deep);

    destroy(&deep);
    destroy(&a);

    return 0;
}