<<<<<<< HEAD
=======
/*
 ================================================
 LIBRARY MANAGEMENT SYSTEM IN C
 Using Singly Linked List
 Daffodil International University
 ================================================
*/

>>>>>>> e56a9cd4c0d01f436844aa91454ea575327ffc3e
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

<<<<<<< HEAD
typedef struct Book {
    int id;
    char title[80];
    char author[50];
    int year;
    int copies;
    int available;
    struct Book *next;
} Book;
=======
struct Book {
    int id;
    char title[100];
    char author[60];
    int year;
    struct Book* next;
};
>>>>>>> e56a9cd4c0d01f436844aa91454ea575327ffc3e

typedef struct Member {
    int id;
    char name[50];
    char email[50];
    int borrowed;
    struct Member *next;
} Member;

<<<<<<< HEAD
typedef struct Transaction {
    int id;
    int book_id;
    int member_id;
    char borrow_date[20];
    char return_date[20];
    int returned;
    struct Transaction *next;
} Transaction;

Book        *bookHead = NULL;
Member      *memberHead = NULL;
Transaction *txnHead = NULL;

int bookIdCounter = 1;
int memberIdCounter = 1;
int txnIdCounter = 1;

void getToday(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
}

void pressEnter() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

void clearScreen() {
    system("clear || cls");
}

void printLine() {
    printf("+----------+--------------------------------+----------------------+--------+-----------+\n");
}

void printTxnLine() {
    printf("+------+--------+---------+------------+------------+----------+\n");
}

Book *findBook(int book_id) {
    Book *current = bookHead;
    while (current) {
        if (current->id == book_id) return current;
        current = current->next;
    }
    return NULL;
}

Member *findMember(int member_id) {
    Member *current = memberHead;
    while (current) {
        if (current->id == member_id) return current;
        current = current->next;
    }
    return NULL;
}

void saveData() {
    FILE *file;

    file = fopen("books.dat", "wb");
    Book *book = bookHead;
    while (book) {
        fwrite(book, sizeof(Book) - sizeof(void *), 1, file);
        book = book->next;
    }
    fclose(file);

    file = fopen("members.dat", "wb");
    Member *member = memberHead;
    while (member) {
        fwrite(member, sizeof(Member) - sizeof(void *), 1, file);
        member = member->next;
    }
    fclose(file);

    file = fopen("txns.dat", "wb");
    Transaction *txn = txnHead;
    while (txn) {
        fwrite(txn, sizeof(Transaction) - sizeof(void *), 1, file);
        txn = txn->next;
    }
    fclose(file);
}

void loadData() {
    FILE *file;
    Book bookTemp;
    Member memberTemp;
    Transaction txnTemp;

    file = fopen("books.dat", "rb");
    if (file) {
        while (fread(&bookTemp, sizeof(Book) - sizeof(void *), 1, file) == 1) {
            Book *newBook = malloc(sizeof(Book));
            *newBook = bookTemp;
            newBook->next = bookHead;
            bookHead = newBook;
            if (newBook->id >= bookIdCounter) bookIdCounter = newBook->id + 1;
=======
// Add a new book
void addBook(int id, char title[], char author[], int year) {
    struct Book* check = head;
    while (check != NULL) {
        if (check->id == id) {
            printf("\n [!] Book ID %d already exists.\n", id);
            return;
>>>>>>> e56a9cd4c0d01f436844aa91454ea575327ffc3e
        }
        fclose(file);
    }

<<<<<<< HEAD
    file = fopen("members.dat", "rb");
    if (file) {
        while (fread(&memberTemp, sizeof(Member) - sizeof(void *), 1, file) == 1) {
            Member *newMember = malloc(sizeof(Member));
            *newMember = memberTemp;
            newMember->next = memberHead;
            memberHead = newMember;
            if (newMember->id >= memberIdCounter) memberIdCounter = newMember->id + 1;
=======
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    newBook->year = year;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    printf("\n \"%s\" added successfully.\n", title);
}

// Delete a book
void deleteBook(int id) {
    if (head == NULL) {
        printf("\n [!] Library is empty.\n");
        return;
    }

    struct Book* curr = head;
    struct Book* prev = NULL;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("\n [!] Book ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    printf("\n \"%s\" deleted.\n", curr->title);
    free(curr);
}

// Search for a book
void searchBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n Book Found:\n");
            printf(" ID: %d\n", temp->id);
            printf(" Title: %s\n", temp->title);
            printf(" Author: %s\n", temp->author);
            printf(" Year: %d\n", temp->year);
            return;
        }
        temp = temp->next;
    }
    printf("\n [!] Book ID %d not found.\n", id);
}

// Update book details
void updateBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n Current -> Title: %s | Author: %s | Year: %d\n",
                   temp->title, temp->author, temp->year);

            printf(" New Title: ");
            scanf(" %[^\n]", temp->title);
            printf(" New Author: ");
            scanf(" %[^\n]", temp->author);
            printf(" New Year: ");
            scanf("%d", &temp->year);

            printf("\n Book ID %d updated.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("\n [!] Book ID %d not found.\n", id);
}

// Display all books
void displayBooks() {
    if (head == NULL) {
        printf("\n [!] No books in library.\n");
        return;
    }

    printf("\n %-5s | %-30s | %-20s | %-4s\n", "ID", "Title", "Author", "Year");
    printf(" ---------------------------------------------------------------\n");

    struct Book* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf(" %-5d | %-30s | %-20s | %-4d\n",
               temp->id, temp->title, temp->author, temp->year);
        temp = temp->next;
        count++;
    }

    printf(" ---------------------------------------------------------------\n");
    printf(" Total: %d book(s)\n", count);
}

// Free all memory before exit
void freeLibrary() {
    struct Book* temp = head;
    while (temp != NULL) {
        struct Book* next = temp->next;
        free(temp);
        temp = next;
    }
}

// Load sample data
void loadSampleData() {
    addBook(101, "Introduction to C", "Dennis Ritchie", 1978);
    addBook(102, "Data Structures", "Mark Allen Weiss", 2011);
    addBook(103, "The Pragmatic Programmer", "David Thomas", 2019);
    addBook(104, "Clean Code", "Robert C. Martin", 2008);
    addBook(105, "Operating Systems", "Andrew S. Tanenbaum", 2014);
    printf("\n Sample data loaded.\n");
}

// Main function
int main() {
    loadSampleData();

    printf("\n ====================================\n");
    printf(" LIBRARY MANAGEMENT SYSTEM\n");
    printf(" ====================================\n");

    int choice, id, year;
    char title[100], author[60];

    do {
        printf("\n --- MENU ---\n");
        printf(" 1. Add Book\n");
        printf(" 2. Delete Book\n");
        printf(" 3. Search Book\n");
        printf(" 4. Update Book\n");
        printf(" 5. Display All Books\n");
        printf(" 0. Exit\n");
        printf(" Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" ID: "); scanf("%d", &id);
                printf(" Title: "); scanf(" %[^\n]", title);
                printf(" Author: "); scanf(" %[^\n]", author);
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
>>>>>>> e56a9cd4c0d01f436844aa91454ea575327ffc3e
        }
        fclose(file);
    }

    file = fopen("txns.dat", "rb");
    if (file) {
        while (fread(&txnTemp, sizeof(Transaction) - sizeof(void *), 1, file) == 1) {
            Transaction *newTxn = malloc(sizeof(Transaction));
            *newTxn = txnTemp;
            newTxn->next = txnHead;
            txnHead = newTxn;
            if (newTxn->id >= txnIdCounter) txnIdCounter = newTxn->id + 1;
        }
        fclose(file);
    }
}

void addBook() {
    Book *newBook = malloc(sizeof(Book));
    newBook->id = bookIdCounter++;

    printf("Title   : "); scanf(" %[^\n]", newBook->title);
    printf("Author  : "); scanf(" %[^\n]", newBook->author);
    printf("Year    : "); scanf("%d", &newBook->year);
    printf("Copies  : "); scanf("%d", &newBook->copies);
    newBook->available = newBook->copies;

    newBook->next = bookHead;
    bookHead = newBook;

    saveData();
    printf("\nBook added successfully! Book ID = %d\n", newBook->id);
}

void listBooks() {
    printf("\n");
    printLine();
    printf("| %-8s | %-30s | %-20s | %-6s | %-9s |\n",
        "Book ID", "Title", "Author", "Year", "Available");
    printLine();

    Book *current = bookHead;
    while (current) {
        char availInfo[15];
        sprintf(availInfo, "%d / %d", current->available, current->copies);
        printf("| %-8d | %-30s | %-20s | %-6d | %-9s |\n",
            current->id, current->title, current->author, current->year, availInfo);
        current = current->next;
    }
    printLine();
}

void searchBook() {
    char query[80];
    printf("Search (title or author): ");
    scanf(" %[^\n]", query);

    int found = 0;
    Book *current = bookHead;

    printf("\n");
    while (current) {
        if (strstr(current->title, query) || strstr(current->author, query)) {
            if (!found) {
                printLine();
                printf("| %-8s | %-30s | %-20s | %-6s | %-9s |\n",
                    "Book ID", "Title", "Author", "Year", "Available");
                printLine();
            }
            char availInfo[15];
            sprintf(availInfo, "%d / %d", current->available, current->copies);
            printf("| %-8d | %-30s | %-20s | %-6d | %-9s |\n",
                current->id, current->title, current->author, current->year, availInfo);
            found = 1;
        }
        current = current->next;
    }

    if (found) printLine();
    else puts("No books found.");
}

void deleteBook() {
    int book_id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &book_id);

    Book *prev = NULL;
    Book *current = bookHead;

    while (current && current->id != book_id) {
        prev = current;
        current = current->next;
    }

    if (!current) { puts("Book not found."); return; }

    if (prev) prev->next = current->next;
    else bookHead = current->next;

    free(current);
    saveData();
    puts("Book deleted successfully.");
}

void addMember() {
    Member *newMember = malloc(sizeof(Member));
    newMember->id = memberIdCounter++;
    newMember->borrowed = 0;

    printf("Name    : "); scanf(" %[^\n]", newMember->name);
    printf("Email   : "); scanf(" %[^\n]", newMember->email);

    newMember->next = memberHead;
    memberHead = newMember;

    saveData();
    printf("\nMember added successfully! Member ID = %d\n", newMember->id);
}

void printMemberLine() {
    printf("+----------+--------------------------+--------------------------------+----------+\n");
}

void listMembers() {
    printf("\n");
    printMemberLine();
    printf("| %-8s | %-24s | %-30s | %-8s |\n",
        "Mbr ID", "Name", "Email", "Borrowed");
    printMemberLine();

    Member *current = memberHead;
    while (current) {
        printf("| %-8d | %-24s | %-30s | %-8d |\n",
            current->id, current->name, current->email, current->borrowed);
        current = current->next;
    }
    printMemberLine();
}

void deleteMember() {
    int member_id;
    printf("Enter Member ID to delete: ");
    scanf("%d", &member_id);

    Member *prev = NULL;
    Member *current = memberHead;

    while (current && current->id != member_id) {
        prev = current;
        current = current->next;
    }

    if (!current) { puts("Member not found."); return; }
    if (current->borrowed > 0) { puts("Member has unreturned books!"); return; }

    if (prev) prev->next = current->next;
    else memberHead = current->next;

    free(current);
    saveData();
    puts("Member deleted successfully.");
}

void borrowBook() {
    int book_id, member_id;
    printf("Book ID   : "); scanf("%d", &book_id);
    printf("Member ID : "); scanf("%d", &member_id);

    Book   *book   = findBook(book_id);
    Member *member = findMember(member_id);

    if (!book)   { puts("Book not found.");   return; }
    if (!member) { puts("Member not found."); return; }
    if (book->available <= 0) { puts("No copies available."); return; }
    if (member->borrowed >= 3) { puts("Borrow limit reached (max 3 books)."); return; }

    Transaction *newTxn = malloc(sizeof(Transaction));
    newTxn->id = txnIdCounter++;
    newTxn->book_id = book_id;
    newTxn->member_id = member_id;
    newTxn->returned = 0;
    getToday(newTxn->borrow_date);
    strcpy(newTxn->return_date, "-");

    newTxn->next = txnHead;
    txnHead = newTxn;

    book->available--;
    member->borrowed++;

    saveData();
    printf("\nBook borrowed! Transaction ID = %d\n", newTxn->id);
}

void returnBook() {
    int txn_id;
    printf("Transaction ID: ");
    scanf("%d", &txn_id);

    Transaction *txn = txnHead;
    while (txn && !(txn->id == txn_id && !txn->returned))
        txn = txn->next;

    if (!txn) { puts("Transaction not found or already returned."); return; }

    getToday(txn->return_date);
    txn->returned = 1;

    Book   *book   = findBook(txn->book_id);
    Member *member = findMember(txn->member_id);

    if (book)   book->available++;
    if (member && member->borrowed > 0) member->borrowed--;

    saveData();
    puts("Book returned successfully.");
}

void listTransactions() {
    printf("\n");
    printTxnLine();
    printf("| %-4s | %-6s | %-7s | %-10s | %-10s | %-8s |\n",
        "ID", "BookID", "MemberID", "Borrowed", "Returned", "Status");
    printTxnLine();

    Transaction *txn = txnHead;
    while (txn) {
        printf("| %-4d | %-6d | %-7d | %-10s | %-10s | %-8s |\n",
            txn->id, txn->book_id, txn->member_id,
            txn->borrow_date, txn->return_date,
            txn->returned ? "Returned" : "Active");
        txn = txn->next;
    }
    printTxnLine();
}

void report() {
    int totalCopies = 0, availableCopies = 0, activeBorrows = 0;
    int totalBooks = 0, totalMembers = 0;

    Book *book = bookHead;
    while (book) {
        totalCopies += book->copies;
        availableCopies += book->available;
        totalBooks++;
        book = book->next;
    }

    Member *member = memberHead;
    while (member) { totalMembers++; member = member->next; }

    Transaction *txn = txnHead;
    while (txn) { if (!txn->returned) activeBorrows++; txn = txn->next; }

    printf("\n+------------------------------+\n");
    printf("|        LIBRARY REPORT        |\n");
    printf("+------------------------------+\n");
    printf("| Total book titles  : %-7d |\n", totalBooks);
    printf("| Total copies       : %-7d |\n", totalCopies);
    printf("| Available copies   : %-7d |\n", availableCopies);
    printf("| Total members      : %-7d |\n", totalMembers);
    printf("| Active borrows     : %-7d |\n", activeBorrows);
    printf("+------------------------------+\n");
}

int main() {
    loadData();
    clearScreen();

    printf("+================================+\n");
    printf("|   LIBRARY MANAGEMENT SYSTEM   |\n");
    printf("|   Data Structure: Linked List  |\n");
    printf("+================================+\n\n");

    char username[30], password[30];
    printf("Username : "); scanf("%s", username);
    printf("Password : "); scanf("%s", password);

    if (strcmp(username, "admin") != 0 || strcmp(password, "admin123") != 0) {
        puts("\nWrong credentials!"); return 1;
    }

    int choice;
    do {
        clearScreen();
        printf("+================================+\n");
        printf("|           MAIN MENU            |\n");
        printf("+================================+\n");
        printf("|  1.  Add Book                  |\n");
        printf("|  2.  List Books                |\n");
        printf("|  3.  Search Book               |\n");
        printf("|  4.  Delete Book               |\n");
        printf("|  5.  Add Member                |\n");
        printf("|  6.  List Members              |\n");
        printf("|  7.  Delete Member             |\n");
        printf("|  8.  Borrow Book               |\n");
        printf("|  9.  Return Book               |\n");
        printf("|  10. All Transactions          |\n");
        printf("|  11. Report                    |\n");
        printf("|  0.  Exit                      |\n");
        printf("+================================+\n");
        printf("Choice: "); scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1:  addBook();           break;
            case 2:  listBooks();         break;
            case 3:  searchBook();        break;
            case 4:  deleteBook();        break;
            case 5:  addMember();         break;
            case 6:  listMembers();       break;
            case 7:  deleteMember();      break;
            case 8:  borrowBook();        break;
            case 9:  returnBook();        break;
            case 10: listTransactions();  break;
            case 11: report();            break;
        }

        if (choice) pressEnter();

    } while (choice != 0);

    puts("Goodbye!");
    return 0;
}
