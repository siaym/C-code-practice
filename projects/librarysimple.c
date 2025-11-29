#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;   // 0 = available, 1 = issued
};

void addBook() {
    struct Book newBook;
    FILE *file = fopen("library.txt", "a");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar();

    printf("Enter Book Title: ");
    fgets(newBook.title, 50, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter Book Author: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.isIssued = 0;

    fprintf(file, "%d|%s|%s|%d\n",newBook.id, newBook.title, newBook.author, newBook.isIssued);

    fclose(file);

    printf("Book added successfully!\n");
}

void displayBooks() {
    struct Book book;
    FILE *file = fopen("library.txt", "r");

    if (!file) {
        printf("No books found!\n");
        return;
    }

    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d\n",
                  &book.id, book.title, book.author, &book.isIssued) == 4) {

        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
               book.id, book.title, book.author,
               book.isIssued ? "Issued" : "Available");
    }

    fclose(file);
}

void issueBook() {
    struct Book book;
    int bookID, found = 0;

    FILE *file = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID to Issue: ");
    scanf("%d", &bookID);

    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d\n",
                  &book.id, book.title, book.author, &book.isIssued) == 4) {

        if (book.id == bookID && book.isIssued == 0) {
            book.isIssued = 1;
            found = 1;
            printf("Book issued successfully!\n");
        }

        fprintf(temp, "%d|%s|%s|%d\n",book.id, book.title, book.author, book.isIssued);
    }

    fclose(file);
    fclose(temp);

    if (!found)
        printf("Book not found or already issued.\n");

    remove("library.txt");
    rename("temp.txt", "library.txt");
}

void returnBook() {
    struct Book book;
    int bookID, found = 0;

    FILE *file = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID to Return: ");
    scanf("%d", &bookID);

    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d\n",
                  &book.id, book.title, book.author, &book.isIssued) == 4) {

        if (book.id == bookID && book.isIssued == 1) {
            book.isIssued = 0;
            found = 1;
            printf("Book returned successfully!\n");
        }

        fprintf(temp, "%d|%s|%s|%d\n", book.id, book.title, book.author, book.isIssued);
    }

    fclose(file);
    fclose(temp);

    if (!found)
        printf("Invalid book ID or book is not issued.\n");

    remove("library.txt");
    rename("temp.txt", "library.txt");
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
