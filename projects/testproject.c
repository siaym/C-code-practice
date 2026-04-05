#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;
    char issuedTo[50];
    struct Book *next;
};

struct Book *head = NULL;

// ================= INSERT =================
void insertBook(struct Book *newBook) {
    newBook->next = head;
    head = newBook;
}

// ================= SEARCH =================
struct Book* findBook(int id) {
    struct Book *temp = head;
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// ================= LOAD FROM FILE =================
void loadFromFile() {
    FILE *file = fopen("library.txt", "r");
    if (!file) return;

    while (1) {
        struct Book *temp = malloc(sizeof(struct Book));

        if (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%49[^\n]\n",
                   &temp->id, temp->title, temp->author,
                   &temp->isIssued, temp->issuedTo) != 5) {
            free(temp);
            break;
        }

        insertBook(temp);
    }

    fclose(file);
}

// ================= SAVE TO FILE =================
void saveToFile() {
    FILE *file = fopen("library.txt", "w");
    struct Book *temp = head;

    while (temp) {
        fprintf(file, "%d|%s|%s|%d|%s\n",
                temp->id, temp->title, temp->author,
                temp->isIssued, temp->issuedTo);
        temp = temp->next;
    }

    fclose(file);
}

// ================= ADD BOOK =================
void addBook() {
    struct Book *newBook = malloc(sizeof(struct Book));

    printf("Enter Book ID: ");
    scanf("%d", &newBook->id);
    getchar();

    printf("Enter Title: ");
    fgets(newBook->title, 50, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(newBook->author, 50, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;

    newBook->isIssued = 0;
    strcpy(newBook->issuedTo, "None");

    insertBook(newBook);
    saveToFile();

    printf("Book added successfully!\n");
}

// ================= DISPLAY =================
void displayBooks() {
    struct Book *temp = head;

    if (!temp) {
        printf("No books found!\n");
        return;
    }

    while (temp) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\nIssued To: %s\n",
               temp->id, temp->title, temp->author,
               temp->isIssued ? "Issued" : "Available",
               temp->issuedTo);
        temp = temp->next;
    }
}

// ================= ISSUE =================
void issueBook() {
    int id;
    char name[50];

    printf("Enter Book ID: ");
    scanf("%d", &id);
    getchar();

    struct Book *book = findBook(id);

    if (!book || book->isIssued) {
        printf("Book not available!\n");
        return;
    }

    printf("Enter Person Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    book->isIssued = 1;
    strcpy(book->issuedTo, name);

    saveToFile();
    printf("Book issued successfully!\n");
}

// ================= RETURN =================
void returnBook() {
    int id;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    struct Book *book = findBook(id);

    if (!book || !book->isIssued) {
        printf("Invalid return!\n");
        return;
    }

    book->isIssued = 0;
    strcpy(book->issuedTo, "None");

    saveToFile();
    printf("Book returned successfully!\n");
}

// ================= DELETE =================
void deleteBook() {
    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    struct Book *temp = head, *prev = NULL;

    while (temp) {
        if (temp->id == id) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            saveToFile();

            printf("Book deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Book not found!\n");
}

// ================= MAIN =================
int main() {
    int choice;

    loadFromFile(); // load existing data

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: deleteBook(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}