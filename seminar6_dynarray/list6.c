#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List init(size_t n) {
    List a = {NULL, NULL, 0};

    for (size_t i = 0; i < n; i++) {
        push_back(&a, (Data){0});
    }

    return a;
}

void push_back(List* pl, Data value) {
    Node* p = malloc(sizeof(Node));

    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    p->value = value;
    p->next = NULL;
    p->prev = pl->tail;

    if (pl->tail != NULL)
        pl->tail->next = p;
    else
        pl->head = p;

    pl->tail = p;
    pl->size++;
}

void push_front(List* pl, Data value) {
    Node* p = malloc(sizeof(Node));

    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    p->value = value;
    p->prev = NULL;
    p->next = pl->head;

    if (pl->head != NULL)
        pl->head->prev = p;
    else
        pl->tail = p;

    pl->head = p;
    pl->size++;
}

Data pop_back(List* pl) {
    if (pl->tail == NULL) {
        fprintf(stderr, "Empty list\n");
        exit(1);
    }

    Node* p = pl->tail;
    Data value = p->value;

    pl->tail = p->prev;

    if (pl->tail != NULL)
        pl->tail->next = NULL;
    else
        pl->head = NULL;

    free(p);
    pl->size--;

    return value;
}

Data pop_front(List* pl) {
    if (pl->head == NULL) {
        fprintf(stderr, "Empty list\n");
        exit(1);
    }

    Node* p = pl->head;
    Data value = p->value;

    pl->head = p->next;

    if (pl->head != NULL)
        pl->head->prev = NULL;
    else
        pl->tail = NULL;

    free(p);
    pl->size--;

    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL)
        return NULL;

    Node* next = p->next;

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        pl->head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;
    else
        pl->tail = p->prev;

    free(p);
    pl->size--;

    return next;
}

void splice(List* pl, Node* p, List* other) {
    if (pl == other || other->size == 0)
        return;

    if (p == NULL) {
        if (pl->tail != NULL) {
            pl->tail->next = other->head;
            other->head->prev = pl->tail;
        } else {
            pl->head = other->head;
        }

        pl->tail = other->tail;
    } else {
        Node* before = p->prev;

        other->head->prev = before;
        other->tail->next = p;
        p->prev = other->tail;

        if (before != NULL)
            before->next = other->head;
        else
            pl->head = other->head;
    }

    pl->size += other->size;

    other->head = NULL;
    other->tail = NULL;
    other->size = 0;
}

void advance(Node** pp, size_t n) {
    if (pp == NULL)
        return;

    for (size_t i = 0; i < n && *pp != NULL; i++) {
        *pp = (*pp)->next;
    }
}

void print(const List* pl, void (*print_value)(Data)) {
    Node* p = pl->head;

    while (p != NULL) {
        print_value(p->value);
        p = p->next;
    }

    printf("\n");
}

void destroy(List* pl) {
    Node* p = pl->head;

    while (p != NULL) {
        Node* next = p->next;
        free(p);
        p = next;
    }

    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}