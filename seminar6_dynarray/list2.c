#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static Node* create_node(int value) {
    Node* p = malloc(sizeof(Node));

    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    p->value = value;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

List init(size_t n) {
    List list = {NULL, NULL, 0};

    for (size_t i = 0; i < n; ++i) {
        push_back(&list, 0);
    }

    return list;
}

void print(const List* pl) {
    for (Node* p = pl->head; p != NULL; p = p->next) {
        printf("%d ", p->value);
    }

    printf("\n");
}

void push_back(List* pl, int value) {
    Node* p = create_node(value);

    p->prev = pl->tail;

    if (pl->tail != NULL) {
        pl->tail->next = p;
    } else {
        pl->head = p;
    }

    pl->tail = p;
    pl->size++;
}

int pop_back(List* pl) {
    if (pl->tail == NULL) {
        fprintf(stderr, "Error: list is empty\n");
        exit(1);
    }

    Node* p = pl->tail;
    int value = p->value;

    pl->tail = p->prev;

    if (pl->tail != NULL) {
        pl->tail->next = NULL;
    } else {
        pl->head = NULL;
    }

    free(p);
    pl->size--;

    return value;
}

void push_front(List* pl, int value) {
    Node* p = create_node(value);

    p->next = pl->head;

    if (pl->head != NULL) {
        pl->head->prev = p;
    } else {
        pl->tail = p;
    }

    pl->head = p;
    pl->size++;
}

int pop_front(List* pl) {
    if (pl->head == NULL) {
        fprintf(stderr, "Error: list is empty\n");
        exit(1);
    }

    Node* p = pl->head;
    int value = p->value;

    pl->head = p->next;

    if (pl->head != NULL) {
        pl->head->prev = NULL;
    } else {
        pl->tail = NULL;
    }

    free(p);
    pl->size--;

    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL) return NULL;

    Node* next = p->next;

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }

    free(p);
    pl->size--;

    return next;
}

void splice(List* plist, Node* p, List* pother) {
    if (plist == pother || pother->size == 0) return;

    if (p == NULL) {
        if (plist->tail != NULL) {
            plist->tail->next = pother->head;
            pother->head->prev = plist->tail;
        } else {
            plist->head = pother->head;
        }

        plist->tail = pother->tail;
    } else {
        Node* before = p->prev;

        pother->head->prev = before;
        pother->tail->next = p;
        p->prev = pother->tail;

        if (before != NULL) {
            before->next = pother->head;
        } else {
            plist->head = pother->head;
        }
    }

    plist->size += pother->size;

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void advance(Node** pp, size_t n) {
    if (pp == NULL) return;

    for (size_t i = 0; i < n && *pp != NULL; ++i) {
        *pp = (*pp)->next;
    }
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