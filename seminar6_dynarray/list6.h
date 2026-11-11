#ifndef LIST_H
#define LIST_H

#include <stddef.h>

#ifndef Data
#define Data int
#endif

typedef struct node {
    Data value;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    size_t size;
} List;

List init(size_t n);
void print(const List* pl, void (*print_value)(Data));
void push_back(List* pl, Data value);
Data pop_back(List* pl);
void push_front(List* pl, Data value);
Data pop_front(List* pl);
Node* erase(List* pl, Node* p);
void splice(List* pl, Node* p, List* other);
void advance(Node** pp, size_t n);
void destroy(List* pl);

#endif