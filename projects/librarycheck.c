#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Constants and Definitions --- */
#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define ISBN_LEN 20
#define NAME_LEN 50
#define PHONE_LEN 20
#define ID_LEN 20
#define FILENAME "library_data.txt"

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char isbn[ISBN_LEN];
    int year;
    int isAvailable; /* 1 = available, 0 = borrowed */

    /* Borrower info */
    char borrowerName[NAME_LEN];
    char borrowerPhone[PHONE_LEN];
    char borrowerID[ID_LEN];

} Book;

/* --- Global Variables --- */
Book library[MAX_BOOKS];
int bookCount = 0;

/* --- Function Prototypes --- */
void loadBooks();
void saveBooks();
void addBook();
void displayBooks();
void searchBook();
void updateBook();
void deleteBook();
void borrowBook();
void returnBook();
void clearInputBuffer();
void removeNewline(char* str);
int findBookIndexByISBN(char* isbn);

/* --- Main Function --- */
int main() {
    int choice;

    loadBooks();

    do {
        printf("\n========================================\n");
        printf("         LIBRARY MANAGEMENT SYSTEM     \n");
        printf("========================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book (Title/ISBN)\n");
        printf("4. Update Book Details\n");
        printf("5. Delete Book\n");
        printf("6. Borrow Book\n");
        printf("7. Return Book\n");
        printf("8. Save & Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n----------------------------------------\n");
            printf("ERROR: Invalid input! Please enter a number.\n");
            printf("----------------------------------------\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: borrowBook(); break;
            case 7: returnBook(); break;
            case 8: saveBooks(); printf("[INFO] Saved and exiting. Goodbye!\n"); break;
            default:
                printf("\n----------------------------------------\n");
                printf("ERROR: Invalid choice! Please try again.\n");
                printf("----------------------------------------\n");
        }
    } while (choice != 8);

    return 0;
}

/* --- Helper Functions --- */

void clearInputBuffer() {
    int c;
    for (; (c = getchar()) != '\n' && c != EOF; ) { }
}

void removeNewline(char* str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int findBookIndexByISBN(char* isbn) {
    int i;
    for (i = 0; i < bookCount; i = i + 1) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            return i;
        }
    }
    return -1;
}

/* --- File Handling (pipe-delimited single-line per book) --- */
/* Format per line:
   Title|Author|ISBN|Year|isAvailable|BorrowerName|BorrowerPhone|BorrowerID
*/
void loadBooks() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("[INFO] No existing database found. A new file will be created on save.\n");
        return;
    }

    char line[1024];
    bookCount = 0;

    while (bookCount < MAX_BOOKS && fgets(line, sizeof(line), fp) != NULL) {
        removeNewline(line);

        /* parse tokens */
        char *token;
        token = strtok(line, "|");
        if (token == NULL) continue;
        strncpy(library[bookCount].title, token, TITLE_LEN);
        library[bookCount].title[TITLE_LEN - 1] = '\0';

        token = strtok(NULL, "|");
        if (token == NULL) { strcpy(library[bookCount].author, "Unknown"); }
        else { strncpy(library[bookCount].author, token, AUTHOR_LEN); library[bookCount].author[AUTHOR_LEN - 1] = '\0'; }

        token = strtok(NULL, "|");
        if (token == NULL) { strcpy(library[bookCount].isbn, ""); }
        else { strncpy(library[bookCount].isbn, token, ISBN_LEN); library[bookCount].isbn[ISBN_LEN - 1] = '\0'; }

        token = strtok(NULL, "|");
        if (token == NULL) library[bookCount].year = 0;
        else library[bookCount].year = atoi(token);

        token = strtok(NULL, "|");
        if (token == NULL) library[bookCount].isAvailable = 1;
        else library[bookCount].isAvailable = atoi(token);

        token = strtok(NULL, "|");
        if (token == NULL) strcpy(library[bookCount].borrowerName, "None");
        else { strncpy(library[bookCount].borrowerName, token, NAME_LEN); library[bookCount].borrowerName[NAME_LEN - 1] = '\0'; }

        token = strtok(NULL, "|");
        if (token == NULL) strcpy(library[bookCount].borrowerPhone, "None");
        else { strncpy(library[bookCount].borrowerPhone, token, PHONE_LEN); library[bookCount].borrowerPhone[PHONE_LEN - 1] = '\0'; }

        token = strtok(NULL, "|");
        if (token == NULL) strcpy(library[bookCount].borrowerID, "None");
        else { strncpy(library[bookCount].borrowerID, token, ID_LEN); library[bookCount].borrowerID[ID_LEN - 1] = '\0'; }

        bookCount = bookCount + 1;
    }

    fclose(fp);
    printf("[INFO] Loaded %d records from %s\n", bookCount, FILENAME);
}

void saveBooks() {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("\n----------------------------------------\n");
        printf("ERROR: Could not open file for writing.\n");
        printf("----------------------------------------\n");
        return;
    }

    int i;
    for (i = 0; i < bookCount; i = i + 1) {
        /* replace any '|' inside fields would be needed in production;
           we assume users do not type '|' in fields for this simple assignment */
        fprintf(fp, "%s|%s|%s|%d|%d|%s|%s|%s\n",
                library[i].title,
                library[i].author,
                library[i].isbn,
                library[i].year,
                library[i].isAvailable,
                library[i].borrowerName,
                library[i].borrowerPhone,
                library[i].borrowerID);
    }

    fclose(fp);
    printf("[SUCCESS] Database saved to %s\n", FILENAME);
}

/* --- Core Features --- */

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\n----------------------------------------\n");
        printf("ERROR: Database is full. Cannot add more books.\n");
        printf("----------------------------------------\n");
        return;
    }

    Book newBook;

    printf("\n--- Add New Book ---\n");
    printf("Enter Title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    removeNewline(newBook.title);

    printf("Enter Author: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    removeNewline(newBook.author);

    printf("Enter ISBN: ");
    fgets(newBook.isbn, ISBN_LEN, stdin);
    removeNewline(newBook.isbn);

    printf("Enter Publication Year: ");
    if (scanf("%d", &newBook.year) != 1) {
        printf("\n----------------------------------------\n");
        printf("ERROR: Invalid year input. Book not added.\n");
        printf("----------------------------------------\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    newBook.isAvailable = 1;
    strcpy(newBook.borrowerName, "None");
    strcpy(newBook.borrowerPhone, "None");
    strcpy(newBook.borrowerID, "None");

    library[bookCount] = newBook;
    bookCount = bookCount + 1;

    printf("\n----------------------------------------\n");
    printf("[SUCCESS] Book added successfully.\n");
    printf("----------------------------------------\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\n[INFO] No books in the library.\n");
        return;
    }

    /* Table header - TITLE column width = 30 */
    printf("\n+------------------------------+-------------------+-----------------+-------+-----------+\n");
    printf("| %-28s | %-17s | %-15s | %-5s | %-9s |\n", "TITLE", "AUTHOR", "ISBN", "YEAR", "STATUS");
    printf("+------------------------------+-------------------+-----------------+-------+-----------+\n");

    int i;
    for (i = 0; i < bookCount; i = i + 1) {
        char status[16];
        if (library[i].isAvailable == 1) {
            strcpy(status, "[OK] Available");
        } else {
            strcpy(status, "[X] Borrowed");
        }

        printf("| %-28s | %-17s | %-15s | %-5d | %-9s |\n",
               library[i].title,
               library[i].author,
               library[i].isbn,
               library[i].year,
               status);
        printf("+------------------------------+-------------------+-----------------+-------+-----------+\n");

        /* If borrowed, show multiline borrower info */
        if (library[i].isAvailable == 0) {
            printf("   Borrower Name : %s\n", library[i].borrowerName);
            printf("   Borrower Phone: %s\n", library[i].borrowerPhone);
            printf("   Borrower ID   : %s\n", library[i].borrowerID);
            printf("   ----------------------------------------\n");
        }
    }
}

void searchBook() {
    char query[100];
    printf("\nEnter Title or ISBN to search: ");
    fgets(query, 100, stdin);
    removeNewline(query);

    int found = 0;
    int i;
    printf("\n--- Search Results ---\n");
    for (i = 0; i < bookCount; i = i + 1) {
        if (strstr(library[i].title, query) != NULL || strcmp(library[i].isbn, query) == 0) {
            printf("\nTitle : %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN  : %s\n", library[i].isbn);
            printf("Year  : %d\n", library[i].year);
            if (library[i].isAvailable == 1) {
                printf("Status: [OK] Available\n");
            } else {
                printf("Status: [X] Borrowed\n");
                printf("   Borrower Name : %s\n", library[i].borrowerName);
                printf("   Borrower Phone: %s\n", library[i].borrowerPhone);
                printf("   Borrower ID   : %s\n", library[i].borrowerID);
            }
            printf("----------------------------------------\n");
            found = found + 1;
        }
    }

    if (found == 0) {
        printf("No matching records found.\n");
    } else {
        printf("Summary: Found %d record(s).\n", found);
    }
}

/* Update Book Details (keeps original style) */
void updateBook() {
    char isbn[ISBN_LEN];
    printf("\nEnter ISBN to update: ");
    fgets(isbn, ISBN_LEN, stdin);
    removeNewline(isbn);

    int index = findBookIndexByISBN(isbn);
    if (index == -1) {
        printf("\n----------------------------------------\n");
        printf("ERROR: Book not found.\n");
        printf("----------------------------------------\n");
        return;
    }

    printf("\nBook Found: %s\n", library[index].title);
    printf("1. Update Availability\n");
    printf("2. Update Title\n");
    printf("3. Cancel\n");
    printf("Choose option: ");

    int sub;
    if (scanf("%d", &sub) != 1) {
        printf("\nERROR: Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    if (sub == 1) {
        printf("Set status (1=Available, 0=Borrowed): ");
        if (scanf("%d", &library[index].isAvailable) != 1) {
            printf("ERROR: Invalid input.\n");
            clearInputBuffer();
            return;
        }
        clearInputBuffer();
        if (library[index].isAvailable == 1) {
            strcpy(library[index].borrowerName, "None");
            strcpy(library[index].borrowerPhone, "None");
            strcpy(library[index].borrowerID, "None");
        }
        printf("[SUCCESS] Availability updated.\n");
    }
    else if (sub == 2) {
        printf("Enter New Title: ");
        fgets(library[index].title, TITLE_LEN, stdin);
        removeNewline(library[index].title);
        printf("[SUCCESS] Title updated.\n");
    }
    else {
        printf("Update cancelled.\n");
    }
}

/* Delete a book by ISBN */
void deleteBook() {
    char isbn[ISBN_LEN];
    printf("\nEnter ISBN to delete: ");
    fgets(isbn, ISBN_LEN, stdin);
    removeNewline(isbn);

    int index = findBookIndexByISBN(isbn);
    if (index == -1) {
        printf("\n----------------------------------------\n");
        printf("ERROR: Book not found. Cannot delete.\n");
        printf("----------------------------------------\n");
        return;
    }

    int i;
    for (i = index; i < bookCount - 1; i = i + 1) {
        library[i] = library[i + 1];
    }
    bookCount = bookCount - 1;

    printf("\n[SUCCESS] Book deleted successfully.\n");
}

/* Borrow Book (collects borrower name, phone, id) */
void borrowBook() {
    char isbn[ISBN_LEN];
    printf("\nEnter ISBN to borrow: ");
    fgets(isbn, ISBN_LEN, stdin);
    removeNewline(isbn);

    int index = findBookIndexByISBN(isbn);
    if (index == -1) {
        printf("\nERROR: Book not found.\n");
        return;
    }

    if (library[index].isAvailable == 0) {
        printf("\nINFO: Book is already borrowed.\n");
        return;
    }

    printf("Enter Borrower Name: ");
    fgets(library[index].borrowerName, NAME_LEN, stdin);
    removeNewline(library[index].borrowerName);

    printf("Enter Borrower Phone: ");
    fgets(library[index].borrowerPhone, PHONE_LEN, stdin);
    removeNewline(library[index].borrowerPhone);

    printf("Enter Borrower ID: ");
    fgets(library[index].borrowerID, ID_LEN, stdin);
    removeNewline(library[index].borrowerID);

    library[index].isAvailable = 0;

    printf("\n[SUCCESS] Book borrowed successfully!\n");
}

/* Return Book requires BOTH ISBN and Borrower ID (Option 3) */
void returnBook() {
    char isbn[ISBN_LEN];
    char id[ID_LEN];

    printf("\nEnter ISBN of book to return: ");
    fgets(isbn, ISBN_LEN, stdin);
    removeNewline(isbn);

    printf("Enter Borrower ID: ");
    fgets(id, ID_LEN, stdin);
    removeNewline(id);

    int index = findBookIndexByISBN(isbn);
    if (index == -1) {
        printf("\nERROR: Book not found.\n");
        return;
    }

    if (strcmp(library[index].borrowerID, id) != 0) {
        printf("\nERROR: Borrower ID does not match our records!\n");
        return;
    }

    library[index].isAvailable = 1;
    strcpy(library[index].borrowerName, "None");
    strcpy(library[index].borrowerPhone, "None");
    strcpy(library[index].borrowerID, "None");

    printf("\n[SUCCESS] Book returned successfully!\n");
}
