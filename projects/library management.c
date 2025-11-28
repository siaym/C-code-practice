#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define STRLEN 128
#define DATA_FILE "books_basic.txt"

typedef struct {
    char title[STRLEN];
    char author[STRLEN];
    char isbn[32];
    int year;
    int available; // 1 available, 0 borrowed
} Book;

Book books[MAX_BOOKS];
int totalBooks = 0;

/* helpers */
void strip_newline(char *s) {
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[n-1] = '\0';
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int is_number(const char *s) {
    if (!s || !*s) return 0;
    for (const char *p = s; *p; ++p) if (!isdigit((unsigned char)*p)) return 0;
    return 1;
}

/* operations */
void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        printf("Library full (%d books). Cannot add more.\n", MAX_BOOKS);
        return;
    }
    Book b;
    printf("Enter title: ");
    fgets(b.title, STRLEN, stdin); strip_newline(b.title);
    if (strlen(b.title) == 0) { printf("Title cannot be empty.\n"); return; }

    printf("Enter author: ");
    fgets(b.author, STRLEN, stdin); strip_newline(b.author);
    if (strlen(b.author) == 0) { printf("Author cannot be empty.\n"); return; }

    printf("Enter ISBN: ");
    fgets(b.isbn, sizeof b.isbn, stdin); strip_newline(b.isbn);

    char yearbuf[32];
    printf("Enter publication year: ");
    fgets(yearbuf, sizeof yearbuf, stdin); strip_newline(yearbuf);
    if (!is_number(yearbuf)) { printf("Invalid year.\n"); return; }
    b.year = atoi(yearbuf);

    b.available = 1;
    books[totalBooks++] = b;
    printf("Book added. Total books: %d\n", totalBooks);
}

void displayBooks() {
    if (totalBooks == 0) { printf("No books to show.\n"); return; }
    printf("---- All Books (%d) ----\n", totalBooks);
    for (int i = 0; i < totalBooks; ++i) {
        Book *b = &books[i];
        printf("[%d] Title: %s\n    Author: %s\n    ISBN: %s\n    Year: %d\n    Status: %s\n",
               i+1, b->title, b->author, b->isbn, b->year, b->available ? "Available" : "Borrowed");
    }
}

int findByISBN(const char *isbn) {
    for (int i = 0; i < totalBooks; ++i) {
        if (strcmp(books[i].isbn, isbn) == 0) return i;
    }
    return -1;
}

void searchBook() {
    printf("Search by (1) Title or (2) ISBN? ");
    char choice[8];
    fgets(choice, sizeof choice, stdin); strip_newline(choice);
    if (choice[0] == '1') {
        char q[STRLEN];
        printf("Enter title (substring match): ");
        fgets(q, STRLEN, stdin); strip_newline(q);
        if (strlen(q) == 0) { printf("Empty query.\n"); return; }
        for (int i = 0; i < totalBooks; ++i) {
            if (strstr(books[i].title, q) != NULL) {
                printf("Found [%d] %s | %s | %s | %d | %s\n", i+1, books[i].title, books[i].author, books[i].isbn, books[i].year, books[i].available ? "Available":"Borrowed");
            }
        }
    } else if (choice[0] == '2') {
        char q[32];
        printf("Enter ISBN: ");
        fgets(q, sizeof q, stdin); strip_newline(q);
        int idx = findByISBN(q);
        if (idx >= 0) {
            Book *b = &books[idx];
            printf("Found [%d] Title: %s | Author: %s | Year: %d | Status: %s\n", idx+1, b->title, b->author, b->year, b->available ? "Available":"Borrowed");
        } else printf("No book with that ISBN.\n");
    } else printf("Invalid choice.\n");
}

void updateBook() {
    char q[32];
    printf("Enter ISBN of book to update: ");
    fgets(q, sizeof q, stdin); strip_newline(q);
    int idx = findByISBN(q);
    if (idx < 0) { printf("Book not found.\n"); return; }
    Book *b = &books[idx];
    printf("Updating book: %s\n", b->title);

    printf("New title (leave blank to keep): ");
    char tmp[STRLEN]; fgets(tmp, STRLEN, stdin); strip_newline(tmp);
    if (strlen(tmp)) strncpy(b->title, tmp, STRLEN);

    printf("New author (leave blank to keep): ");
    fgets(tmp, STRLEN, stdin); strip_newline(tmp);
    if (strlen(tmp)) strncpy(b->author, tmp, STRLEN);

    printf("New publication year (leave blank to keep): ");
    char yearbuf[32];
    fgets(yearbuf, sizeof yearbuf, stdin); strip_newline(yearbuf);
    if (strlen(yearbuf)) {
        if (is_number(yearbuf)) b->year = atoi(yearbuf);
        else printf("Invalid year input; keeping old year.\n");
    }
    printf("Update complete.\n");
}

void saveToFile() {
    FILE *f = fopen(DATA_FILE, "w");
    if (!f) { perror("fopen"); return; }
    for (int i = 0; i < totalBooks; ++i) {
        // simple CSV (no escaping)
        fprintf(f, "%s|%s|%s|%d|%d\n",
                books[i].title, books[i].author, books[i].isbn, books[i].year, books[i].available);
    }
    fclose(f);
    printf("Saved %d records to %s\n", totalBooks, DATA_FILE);
}

void loadFromFile() {
    FILE *f = fopen(DATA_FILE, "r");
    if (!f) {
        printf("No saved data found (%s).\n", DATA_FILE);
        return;
    }
    totalBooks = 0;
    char line[512];
    while (fgets(line, sizeof line, f) && totalBooks < MAX_BOOKS) {
        strip_newline(line);
        char *p = strtok(line, "|");
        if (!p) continue;
        strncpy(books[totalBooks].title, p, STRLEN);

        p = strtok(NULL, "|"); if (!p) continue;
        strncpy(books[totalBooks].author, p, STRLEN);

        p = strtok(NULL, "|"); if (!p) continue;
        strncpy(books[totalBooks].isbn, p, sizeof books[totalBooks].isbn);

        p = strtok(NULL, "|"); if (!p) continue;
        books[totalBooks].year = atoi(p);

        p = strtok(NULL, "|"); if (!p) continue;
        books[totalBooks].available = atoi(p);

        totalBooks++;
    }
    fclose(f);
    printf("Loaded %d records from %s\n", totalBooks, DATA_FILE);
}

void menu() {
    while (1) {
        printf("\nLibrary Menu\n1.Add Book\n2.Display All\n3.Search Book\n4.Update Book\n5.Save\n6.Load\n7.Exit\nChoose: ");
        char c[8]; fgets(c, sizeof c, stdin);
        switch (c[0]) {
            case '1': addBook(); break;
            case '2': displayBooks(); break;
            case '3': searchBook(); break;
            case '4': updateBook(); break;
            case '5': saveToFile(); break;
            case '6': loadFromFile(); break;
            case '7': printf("Exiting.\n"); return;
            default: printf("Invalid option.\n");
        }
    }
}

int main() {
    printf("Library Management - Basic Version\n");
    loadFromFile();
    menu();
    return 0;
}
