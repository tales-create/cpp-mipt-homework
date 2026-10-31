
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};

typedef struct book Book;

struct book_dynamic {
    char* title;
    int pages;
    float price;
};

typedef struct book_dynamic BookDynamic;

struct library {
    BookDynamic* books;
    int number_of_books;
};

typedef struct library Library;

void print_book(const Book* b) {
    printf("Title: %s, Pages: %i, Price: %.1f\n",
           b->title, b->pages, b->price);
}

void print_book_dynamic(const BookDynamic* b) {
    if (b == NULL || b->title == NULL)
        return;

    printf("Title: %s, Pages: %i, Price: %.1f\n",
           b->title, b->pages, b->price);
}

void library_create(Library* lib, int n) {
    lib->books = NULL;
    lib->number_of_books = 0;

    if (n <= 0)
        return;

    lib->books = calloc(n, sizeof(BookDynamic));

    if (lib->books == NULL)
        return;

    lib->number_of_books = n;
}

void library_set(Library lib, int index,
                 const char* title, int pages, float price) {
    if (index < 0 || index >= lib.number_of_books || title == NULL)
        return;

    char* new_title = malloc(strlen(title) + 1);

    if (new_title == NULL)
        return;

    strcpy(new_title, title);

    free(lib.books[index].title);

    lib.books[index].title = new_title;
    lib.books[index].pages = pages;
    lib.books[index].price = price;
}

BookDynamic* library_get(Library lib, int index) {
    if (index < 0 || index >= lib.number_of_books)
        return NULL;

    return &lib.books[index];
}

void library_print(Library lib) {
    for (int i = 0; i < lib.number_of_books; ++i) {
        print_book_dynamic(&lib.books[i]);
    }
}

void library_destroy(Library* lib) {
    if (lib == NULL)
        return;

    for (int i = 0; i < lib->number_of_books; ++i) {
        free(lib->books[i].title);
    }

    free(lib->books);

    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {

    printf("1a:\n");

    size_t* p_a = malloc(sizeof(size_t));
    if (p_a == NULL) return 1;

    *p_a = 123;
    printf("%zu\n", *p_a);
    free(p_a);


    printf("\n1b:\n");

    char* p_b = malloc(9 * sizeof(char));
    if (p_b == NULL) return 1;

    strcpy(p_b, "Elephant");
    printf("%s\n", p_b);
    free(p_b);


    printf("\n1c:\n");

    char* str_c = malloc(14 * sizeof(char));
    if (str_c == NULL) return 1;

    strcpy(str_c, "Cats and Dogs");

    char** p_c = malloc(sizeof(char*));

    if (p_c == NULL) {
        free(str_c);
        return 1;
    }

    *p_c = str_c;

    printf("%s\n", *p_c);

    free(*p_c);
    free(p_c);


    printf("\n1d:\n");

    Book* p_d = malloc(sizeof(Book));
    if (p_d == NULL) return 1;

    strcpy(p_d->title, "Don Quixote");
    p_d->pages = 1000;
    p_d->price = 750.0f;

    print_book(p_d);
    free(p_d);


    printf("\n1e:\n");

    Book local_book;

    strcpy(local_book.title, "Don Quixote");
    local_book.pages = 1000;
    local_book.price = 750.0f;

    Book** p_e = malloc(sizeof(Book*));
    if (p_e == NULL) return 1;

    *p_e = &local_book;

    print_book(*p_e);

    free(p_e);


    printf("\n1f:\n");

    Book** p_f = malloc(sizeof(Book*));
    if (p_f == NULL) return 1;

    *p_f = malloc(sizeof(Book));

    if (*p_f == NULL) {
        free(p_f);
        return 1;
    }

    strcpy((*p_f)->title, "Don Quixote");
    (*p_f)->pages = 1000;
    (*p_f)->price = 750.0f;

    print_book(*p_f);

    free(*p_f);
    free(p_f);


    printf("\n1g:\n");

    Book* p_g = malloc(3 * sizeof(Book));
    if (p_g == NULL) return 1;

    strcpy(p_g[0].title, "Don Quixote");
    p_g[0].pages = 1000;
    p_g[0].price = 750.0f;

    strcpy(p_g[1].title, "Oblomov");
    p_g[1].pages = 400;
    p_g[1].price = 250.0f;

    strcpy(p_g[2].title, "The Odyssey");
    p_g[2].pages = 500;
    p_g[2].price = 500.0f;

    for (int i = 0; i < 3; ++i) {
        print_book(&p_g[i]);
    }

    free(p_g);


    printf("\n1h:\n");

    BookDynamic* p_h = malloc(sizeof(BookDynamic));
    if (p_h == NULL) return 1;

    p_h->title = malloc(strlen("Don Quixote") + 1);

    if (p_h->title == NULL) {
        free(p_h);
        return 1;
    }

    strcpy(p_h->title, "Don Quixote");
    p_h->pages = 1000;
    p_h->price = 750.0f;

    print_book_dynamic(p_h);

    free(p_h->title);
    free(p_h);


    printf("\n1i:\n");

    Library a;

    library_create(&a, 3);

    if (a.books == NULL) return 1;

    library_set(a, 0, "Don Quixote", 1000, 750.0f);
    library_set(a, 1, "Oblomov", 400, 250.0f);
    library_set(a, 2, "The Odyssey", 500, 500.0f);

    library_print(a);

    print_book_dynamic(library_get(a, 1));

    library_destroy(&a);

    return 0;
}
