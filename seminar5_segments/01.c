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
    printf("Title: %s, Pages: %i, Price: %.1f\n", b->title, b->pages, b->price);
}

void print_book_dynamic(const BookDynamic* b) {
    printf("Title: %s, Pages: %i, Price: %.1f\n", b->title, b->pages, b->price);
}

void library_create(Library* lib, int n) {
    lib->number_of_books = n;
    lib->books = (BookDynamic*)malloc(n * sizeof(BookDynamic));
}

void library_set(Library* lib, int index, const char* title, int pages, float price) {
    lib->books[index].title = (char*)malloc((strlen(title) + 1) * sizeof(char));
    strcpy(lib->books[index].title, title);
    lib->books[index].pages = pages;
    lib->books[index].price = price;
}

BookDynamic* library_get(Library* lib, int index) {
    return &(lib->books[index]);
}

void library_print(Library* lib) {
    for (int i = 0; i < lib->number_of_books; ++i) {
        print_book_dynamic(&(lib->books[i]));
    }
}

void library_destroy(Library* lib) {
    for (int i = 0; i < lib->number_of_books; ++i) {
        free(lib->books[i].title);
    }
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {
    size_t* p_a = (size_t*)malloc(sizeof(size_t));
    *p_a = 123;
    free(p_a);

    char* p_b = (char*)malloc(9 * sizeof(char));
    strcpy(p_b, "Elephant");
    free(p_b);

    char* str_c = (char*)malloc(14 * sizeof(char));
    strcpy(str_c, "Cats and Dogs");
    char** p_c = (char**)malloc(sizeof(char*));
    *p_c = str_c;
    free(p_c);
    free(str_c);

    Book* p_d = (Book*)malloc(sizeof(Book));
    strcpy(p_d->title, "Don Quixote");
    p_d->pages = 1000;
    p_d->price = 750.0f;
    free(p_d);

    Book local_book;
    strcpy(local_book.title, "Don Quixote");
    local_book.pages = 1000;
    local_book.price = 750.0f;
    Book* p_e = &local_book;

    Book* p_f = (Book*)malloc(sizeof(Book));
    strcpy(p_f->title, "Don Quixote");
    p_f->pages = 1000;
    p_f->price = 750.0f;
    free(p_f);

    Book* p_g = (Book*)malloc(3 * sizeof(Book));
    strcpy(p_g[0].title, "Don Quixote"); p_g[0].pages = 1000; p_g[0].price = 750.0f;
    strcpy(p_g[1].title, "Oblomov");     p_g[1].pages = 400;  p_g[1].price = 250.0f;
    strcpy(p_g[2].title, "The Odyssey"); p_g[2].pages = 500;  p_g[2].price = 500.0f;
    free(p_g);

    BookDynamic* p_h = (BookDynamic*)malloc(sizeof(BookDynamic));
    p_h->title = (char*)malloc(12 * sizeof(char));
    strcpy(p_h->title, "Don Quixote");
    p_h->pages = 1000;
    p_h->price = 750.0f;
    free(p_h->title);
    free(p_h);

    Library a;
    library_create(&a, 3);
    library_set(&a, 0, "Don Quixote", 1000, 750.0f);
    library_set(&a, 1, "Oblomov", 400, 250.0f);
    library_set(&a, 2, "The Odyssey", 500, 500.0f);
    library_print(&a);
    print_book_dynamic(library_get(&a, 1));
    library_destroy(&a);

    return 0;
}