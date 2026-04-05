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

// ===== UI HELPERS =====
void clearScreen() {
    system("cls || clear");
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void printHeader(const char *title) {
    printf("\n========================================\n");
    printf("        %s\n", title);
    printf("========================================\n");
}

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

// ================= LOAD =================
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

// ================= SAVE =================
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

// ================= ADD =================
void addBook() {
    clearScreen();
    printHeader("ADD NEW BOOK");

    struct Book *newBook = malloc(sizeof(struct Book));

    printf("Enter Book ID   : ");
    scanf("%d", &newBook->id);
    getchar();

    printf("Enter Title     : ");
    fgets(newBook->title, 50, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0;

    printf("Enter Author    : ");
    fgets(newBook->author, 50, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;

    newBook->isIssued = 0;
    strcpy(newBook->issuedTo, "None");

    insertBook(newBook);
    saveToFile();

    printf("\n[✓] Book added successfully!\n");
    pauseScreen();
}

// ================= DISPLAY =================
void displayBooks() {
    clearScreen();
    printHeader("ALL BOOKS");

    struct Book *temp = head;

    if (!temp) {
        printf("No books available.\n");
        pauseScreen();
        return;
    }

    printf("%-5s %-20s %-20s %-10s %-15s\n",
           "ID", "Title", "Author", "Status", "Issued To");
    printf("---------------------------------------------------------------------\n");

    while (temp) {
        printf("%-5d %-20s %-20s %-10s %-15s\n",
               temp->id,
               temp->title,
               temp->author,
               temp->isIssued ? "Issued" : "Free",
               temp->issuedTo);
        temp = temp->next;
    }

    pauseScreen();
}

// ================= ISSUE =================
void issueBook() {
    clearScreen();
    printHeader("ISSUE BOOK");

    int id;
    char name[50];

    printf("Enter Book ID   : ");
    scanf("%d", &id);
    getchar();

    struct Book *book = findBook(id);

    if (!book || book->isIssued) {
        printf("\n[!] Book not available!\n");
        pauseScreen();
        return;
    }

    printf("Enter Person    : ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    book->isIssued = 1;
    strcpy(book->issuedTo, name);

    saveToFile();
    printf("\n[✓] Book issued successfully!\n");
    pauseScreen();
}

// ================= RETURN =================
void returnBook() {
    clearScreen();
    printHeader("RETURN BOOK");

    int id;
    printf("Enter Book ID   : ");
    scanf("%d", &id);

    struct Book *book = findBook(id);

    if (!book || !book->isIssued) {
        printf("\n[!] Invalid return!\n");
        pauseScreen();
        return;
    }

    book->isIssued = 0;
    strcpy(book->issuedTo, "None");

    saveToFile();
    printf("\n[✓] Book returned successfully!\n");
    pauseScreen();
}

// ================= DELETE =================
void deleteBook() {
    clearScreen();
    printHeader("DELETE BOOK");

    int id;
    printf("Enter Book ID   : ");
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

            printf("\n[✓] Book deleted successfully!\n");
            pauseScreen();
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\n[!] Book not found!\n");
    pauseScreen();
}

// ================= MAIN =================
int main() {
    int choice;

    loadFromFile();

    while (1) {
        clearScreen();
        printHeader("LIBRARY MANAGEMENT SYSTEM");

        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: deleteBook(); break;
            case 6:
                printf("\nExiting system...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                pauseScreen();
        }
    }
}