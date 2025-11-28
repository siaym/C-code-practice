#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Constants and Definitions --- */
#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define ISBN_LEN 20
// CHANGED: File extension is now .txt
#define FILENAME "library_data.txt"

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char isbn[ISBN_LEN];
    int year;
    int isAvailable; // 1 for Available, 0 for Borrowed
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
void clearInputBuffer();
void removeNewline(char* str);
int findBookIndexByISBN(char* isbn);

/* --- Main Function --- */
int main() {
    int choice;

    // Load data immediately upon starting
    loadBooks();

    do {
        printf("\n========================================\n");
        printf("    LIBRARY BOOK MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book (Title/ISBN)\n");
        printf("4. Update Book Details\n");
        printf("5. Save & Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Consume the newline character left by scanf

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: 
                saveBooks(); 
                printf("Exiting system. Goodbye!\n");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/* --- Function Definitions --- */

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removeNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int findBookIndexByISBN(char* isbn) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            return i;
        }
    }
    return -1;
}

// CHANGED: Now reads from a text file
void loadBooks() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("[INFO] No existing database found. Starting fresh.\n");
        return;
    }
    
    bookCount = 0;
    
    /* We read the file in groups of 5 lines:
       1. Title
       2. Author
       3. ISBN
       4. Year
       5. Availability
    */
    char buffer[20]; // Temp buffer for reading numbers safely

    // While we can successfully read a title, keep going
    while (bookCount < MAX_BOOKS && fgets(library[bookCount].title, TITLE_LEN, fp) != NULL) {
        removeNewline(library[bookCount].title);

        fgets(library[bookCount].author, AUTHOR_LEN, fp);
        removeNewline(library[bookCount].author);

        fgets(library[bookCount].isbn, ISBN_LEN, fp);
        removeNewline(library[bookCount].isbn);

        // Read Year
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            library[bookCount].year = atoi(buffer);
        }

        // Read Availability
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            library[bookCount].isAvailable = atoi(buffer);
        }

        bookCount++;
    }

    fclose(fp);
    printf("[INFO] Loaded %d records from text database.\n", bookCount);
}

// CHANGED: Now writes to a text file
void saveBooks() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("[ERROR] Could not open file for writing!\n");
        return;
    }
    
    for (int i = 0; i < bookCount; i++) {
        fprintf(fp, "%s\n", library[i].title);
        fprintf(fp, "%s\n", library[i].author);
        fprintf(fp, "%s\n", library[i].isbn);
        fprintf(fp, "%d\n", library[i].year);
        fprintf(fp, "%d\n", library[i].isAvailable);
    }

    fclose(fp);
    printf("[SUCCESS] Database saved to %s successfully.\n", FILENAME);
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("[ERROR] Database is full! Cannot add more books.\n");
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
        printf("[ERROR] Invalid year entered.\n");
        clearInputBuffer();
        return;
    }
    
    newBook.isAvailable = 1; 
    
    library[bookCount] = newBook;
    bookCount++;
    
    printf("[SUCCESS] Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("[INFO] No books in the library.\n");
        return;
    }

    printf("\n%-30s %-20s %-15s %-6s %-10s\n", "Title", "Author", "ISBN", "Year", "Status");
    printf("----------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %-15s %-6d %-10s\n", 
               library[i].title, 
               library[i].author, 
               library[i].isbn, 
               library[i].year,
               library[i].isAvailable ? "Available" : "Borrowed");
    }
}

void searchBook() {
    char query[100];
    int totalFound = 0;
    int availableCount = 0;

    printf("\nEnter Title or ISBN to search: ");
    fgets(query, 100, stdin);
    removeNewline(query);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) != NULL || strcmp(library[i].isbn, query) == 0) {
            printf("Found: '%s' by %s (ISBN: %s) - Status: %s\n", 
                   library[i].title, 
                   library[i].author, 
                   library[i].isbn,
                   library[i].isAvailable ? "Available" : "Borrowed");
            
            totalFound++;
            if (library[i].isAvailable == 1) {
                availableCount++;
            }
        }
    }

    if (totalFound == 0) {
        printf("No matching records found.\n");
    } else {
        printf("----------------------------------------\n");
        printf("Summary: Found %d copie(s). %d are currently Available.\n", totalFound, availableCount);
    }
}

void updateBook() {
    char isbn[ISBN_LEN];
    printf("\nEnter ISBN of the book to update: ");
    fgets(isbn, ISBN_LEN, stdin);
    removeNewline(isbn);

    int index = findBookIndexByISBN(isbn);
    if (index == -1) {
        printf("[ERROR] Book not found.\n");
        return;
    }

    printf("Book Found: %s\n", library[index].title);
    printf("1. Update Availability Status\n");
    printf("2. Update Title\n");
    printf("3. Cancel\n");
    printf("Select option: ");
    
    int subChoice;
    scanf("%d", &subChoice);
    clearInputBuffer();

    switch(subChoice) {
        case 1:
            printf("Set status (1 for Available, 0 for Borrowed): ");
            scanf("%d", &library[index].isAvailable);
            clearInputBuffer();
            printf("[SUCCESS] Status updated.\n");
            break;
        case 2:
            printf("Enter new Title: ");
            fgets(library[index].title, TITLE_LEN, stdin);
            removeNewline(library[index].title);
            printf("[SUCCESS] Title updated.\n");
            break;
        case 3:
            printf("Update cancelled.\n");
            break;
        default:
            printf("Invalid option.\n");
    }
}