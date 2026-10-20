#include <stdio.h>

struct node {
    int value;
    struct node* ptr;
};
typedef struct node Node;

int main(void) {

    Node n1 = {100, NULL};
    Node n2 = {200, NULL};
    Node n3 = {300, NULL};

    n1.ptr = &n2;
    n2.ptr = &n3;
    n3.ptr = &n1;

    Node* current = &n1;
    while (1) {
        printf("%d\n", (*current).value);
        current = (*current).ptr;
    }

    return 0;
}