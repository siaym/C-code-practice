/*
 ================================================
   LIBRARY MANAGEMENT SYSTEM IN C
   Using Linked List & Stack
 ================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book {
    int    id;
    char   title[100];
    char   author[60];
    int    year;
    int    available;  
    struct Book* next;
};

struct BorrowStack {
    int    bookId;
    char   bookTitle[100];
    struct BorrowStack* next;
};


struct Book*        head = NULL;
struct BorrowStack* top  = NULL;


/* Add new book */
void addBook(int id, char title[], char author[], int year) {
    struct Book* check = head;
    while (check != NULL) {
        if (check->id == id) {
            printf("\n  [!] Book ID %d already exists.\n", id);
            return;
        }
        check = check->next;
    }

    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id        = id;
    strcpy(newBook->title,  title);
    strcpy(newBook->author, author);
    newBook->year      = year;
    newBook->available = 1;
    newBook->next      = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newBook;
    }
    printf("\n  [+] Book \"%s\" added successfully.\n", title);
}

/* Delete book by ID */
void deleteBook(int id) {
    if (head == NULL) { printf("\n  [!] Library is empty.\n"); return; }

    struct Book* curr = head;
    struct Book* prev = NULL;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) { printf("\n  [!] Book ID %d not found.\n", id); return; }

    if (curr->available == 0) {
        printf("\n  [!] Cannot delete — book is currently borrowed.\n");
        return;
    }

    if (prev == NULL) head = curr->next;
    else              prev->next = curr->next;

    printf("\n  [-] Book \"%s\" deleted.\n", curr->title);
    free(curr);
}

/* Search book by ID */
void searchBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n  Book Found:\n");
            printf("  %-10s: %d\n",   "ID",     temp->id);
            printf("  %-10s: %s\n",   "Title",  temp->title);
            printf("  %-10s: %s\n",   "Author", temp->author);
            printf("  %-10s: %d\n",   "Year",   temp->year);
            
            char* status;
            if (temp->available) status = "Available";
            else status = "Borrowed";
            printf("  %-10s: %s\n\n", "Status", status);
            return;
        }
        temp = temp->next;
    }
    printf("\n  [!] Book ID %d not found.\n", id);
}

/* Update book info by ID */
void updateBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n  Current — Title: %s | Author: %s | Year: %d\n",
                   temp->title, temp->author, temp->year);
            printf("  New Title  : "); scanf(" %[^\n]", temp->title);
            printf("  New Author : "); scanf(" %[^\n]", temp->author);
            printf("  New Year   : "); scanf("%d", &temp->year);
            printf("\n  [*] Book ID %d updated.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("\n  [!] Book ID %d not found.\n", id);
}

/* Display all books */
void displayBooks() {
    if (head == NULL) { printf("\n  [!] No books in library.\n"); return; }

    printf("\n  ID | Title | Author | Year | Status\n");
    printf("  ----+-------+--------+------+----------\n");

    struct Book* temp = head;
    int count = 0;
    while (temp != NULL) {
        char* status;
        if (temp->available) status = "Available";
        else status = "Borrowed";
        
        printf("  %d | %s | %s | %d | %s\n",
               temp->id, temp->title, temp->author, temp->year, status);
        temp = temp->next;
        count++;
    }
    printf("  Total: %d book(s)\n", count);
}



/* Borrow a book — PUSH */
void borrowBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->available == 0) {
                printf("\n  [!] Book is already borrowed.\n");
                return;
            }
            struct BorrowStack* node = (struct BorrowStack*)malloc(sizeof(struct BorrowStack));
            node->bookId = id;
            strcpy(node->bookTitle, temp->title);
            node->next = top;
            top = node;

            temp->available = 0;
            printf("\n  [>] Book \"%s\" borrowed.\n", temp->title);
            return;
        }
        temp = temp->next;
    }
    printf("\n  [!] Book ID %d not found.\n", id);
}

/* Return a book — POP */
void returnBook() {
    if (top == NULL) { printf("\n  [!] No books currently borrowed.\n"); return; }

    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == top->bookId) { temp->available = 1; break; }
        temp = temp->next;
    }

    printf("\n  [<] Book \"%s\" returned.\n", top->bookTitle);
    struct BorrowStack* old = top;
    top = top->next;
    free(old);

    if (top != NULL)
        printf("  [?] Next borrowed: \"%s\"\n", top->bookTitle);
}

/* Show all borrowed books */
void displayBorrowed() {
    if (top == NULL) { printf("\n  [!] No books currently borrowed.\n"); return; }

    printf("\n  Currently Borrowed:\n");
    struct BorrowStack* temp = top;
    int i = 1;
    while (temp != NULL) {
        printf("  %d. [ID: %d] %s\n", i++, temp->bookId, temp->bookTitle);
        temp = temp->next;
    }
    printf("\n");
}

// SAMPLE DATA

void loadSampleData() {
    addBook(101, "Introduction to C",       "Dennis Ritchie",   1978);
    addBook(102, "Data Structures",          "Mark Allen Weiss", 2011);
    addBook(103, "The Pragmatic Programmer", "David Thomas",     2019);
    addBook(104, "Clean Code",               "Robert C. Martin", 2008);
    addBook(105, "Operating Systems",        "Tanenbaum",        2014);
}


int main() {
    loadSampleData();

    int  choice, id, year;
    char title[100], author[60];

    printf("\n  ====================================\n");
    printf("     LIBRARY MANAGEMENT SYSTEM\n");
    printf("  ====================================\n");

    do {
        printf("\n  --- MENU ---\n");
        printf("  1. Add Book\n");
        printf("  2. Delete Book\n");
        printf("  3. Search Book\n");
        printf("  4. Update Book\n");
        printf("  5. Display All Books\n");
        printf("  6. Borrow a Book\n");
        printf("  7. Return a Book\n");
        printf("  8. View Borrowed Books\n");
        printf("  0. Exit\n");
        printf("  Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("  ID     : "); scanf("%d",      &id);
                printf("  Title  : "); scanf(" %[^\n]", title);
                printf("  Author : "); scanf(" %[^\n]", author);
                printf("  Year   : "); scanf("%d",      &year);
                addBook(id, title, author, year);
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
            case 6:
                printf("  Book ID to borrow: "); scanf("%d", &id);
                borrowBook(id);
                break;
            case 7:
                returnBook();
                break;
            case 8:
                displayBorrowed();
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