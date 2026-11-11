#include <stdio.h>
#include "list.h"

void print_value(Data x) {
    printf("%d ", x);
}

int main(void) {
    List a = init(0);

    push_back(&a, 10);
    push_back(&a, 20);
    push_back(&a, 30);

    push_front(&a, 5);

    print(&a, print_value);

    printf("Deleted: %d\n", pop_back(&a));

    print(&a, print_value);

    Node* p = a.head;
    advance(&p, 1);

    p = erase(&a, p);

    print(&a, print_value);

    List b = init(0);

    push_back(&b, 100);
    push_back(&b, 200);

    splice(&a, p, &b);

    print(&a, print_value);
    print(&b, print_value);

    printf("Deleted: %d\n", pop_front(&a));

    print(&a, print_value);

    destroy(&a);
    destroy(&b);

    return 0;
}