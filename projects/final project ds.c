/*
 ================================================
   LIBRARY MANAGEMENT SYSTEM IN C
   Using Singly Linked List
   Daffodil International University
 ================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int          id;
    char         title[100];
    char         author[60];
    int          year;
    struct Book* next;
};

struct Book* head = NULL;

void addBook(int id, char title[], char author[], int year, int silent) {

    /* Check for duplicate ID */
    struct Book* check = head;
    while (check != NULL) {
        if (check->id == id) {
            printf("\n  [!] Book ID %d already exists.\n", id);
            return;
        }
        check = check->next;
    }

    /* Allocate and fill new node */
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id   = id;
    newBook->year = year;
    strcpy(newBook->title,  title);
    strcpy(newBook->author, author);
    newBook->next = NULL;

    /* Append at tail */
    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newBook;
    }

    if (!silent) printf("\n  [+] \"%s\" added successfully.\n", title);
}

void deleteBook(int id) {

    if (head == NULL) {
        printf("\n  [!] Library is empty.\n");
        return;
    }

    struct Book* curr = head;
    struct Book* prev = NULL;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("\n  [!] Book ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) head = curr->next;
    else              prev->next = curr->next;

    printf("\n  [-] \"%s\" deleted.\n", curr->title);
    free(curr);
}

void searchBook(int id) {

    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n  Book Found:\n");
            printf("    ID: %d\n", temp->id);
            printf("    Title: %s\n", temp->title);
            printf("    Author: %s\n", temp->author);
            printf("    Year: %d\n\n", temp->year);
            return;
        }
        temp = temp->next;
    }

    printf("\n  [!] Book ID %d not found.\n", id);
}

void updateBook(int id) {

    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n  Current -> Title: %s | Author: %s | Year: %d\n",
                   temp->title, temp->author, temp->year);
            printf("  New Title: "); scanf(" %[^\n]", temp->title);
            printf("  New Author: "); scanf(" %[^\n]", temp->author);
            printf("  New Year: "); scanf("%d", &temp->year);
            printf("\n  [*] Book ID %d updated.\n", id);
            return;
        }
        temp = temp->next;
    }

    printf("\n  [!] Book ID %d not found.\n", id);
}

void displayBooks() {

    if (head == NULL) {
        printf("\n  [!] No books in library.\n");
        return;
    }

    printf("\n  ID | Title | Author | Year\n");
    printf("  ------------------------------------\n");

    struct Book* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("  %d | %s | %s | %d\n",
               temp->id, temp->title, temp->author, temp->year);
        temp = temp->next;
        count++;
    }

    printf("  ------------------------------------\n");
    printf("  Total: %d book(s)\n", count);
}

void loadSampleData() {
    addBook(101, "Introduction to C",        "Dennis Ritchie",    1978, 1);
    addBook(102, "Data Structures",           "Mark Allen Weiss",  2011, 1);
    addBook(103, "The Pragmatic Programmer",  "David Thomas",      2019, 1);
    addBook(104, "Clean Code",                "Robert C. Martin",  2008, 1);
    addBook(105, "Operating Systems",         "Tanenbaum",         2014, 1);
    printf("\nSample data loaded.\n");
}

int main() {
    loadSampleData();

    printf("\n  ====================================\n");
    printf("       LIBRARY MANAGEMENT SYSTEM\n");
    printf("  ====================================\n");

    int choice, id, year;
    char title[100], author[60];

    do {
        printf("\n  --- MENU ---\n");
        printf("  1. Add Book\n");
        printf("  2. Delete Book\n");
        printf("  3. Search Book\n");
        printf("  4. Update Book\n");
        printf("  5. Display All Books\n");
        printf("  0. Exit\n");
        printf("  Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("  ID: "); scanf("%d", &id);
                printf("  Title: "); scanf(" %[^\n]", title);
                printf("  Author: "); scanf(" %[^\n]", author);
                printf("  Year: "); scanf("%d", &year);
                addBook(id, title, author, year, 0);
                break;
            case 2:
                printf("  Book ID to delete: "); scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("  Book ID to search: "); scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                printf("  Book ID to update: "); scanf("%d", &id);
                updateBook(id);
                break;
            case 5:
                displayBooks();
                break;
            case 0:
                printf("\n  Goodbye!\n\n");
                break;
            default:
                printf("\n  [!] Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}