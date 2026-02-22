#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[50];
    struct node *next;
};

struct node *head = NULL;

struct node *createnode(int roll, char name[])
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->roll = roll;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

// inserting at last
void insertlast(int roll, char name[])
{
    struct node *newnode = createnode(roll,name);

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// printing from front
void printfront()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d--%s\n",temp->roll,temp->name);
        temp = temp->next;
    }
}

// delete from front
void deletefront()
{
    if(head == NULL) return;

    struct node *temp = head;
    head = head->next;
    free(temp);
}

// delete from last
void deletelast()
{
    if(head == NULL) return;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// insert at front
void insertfront(int roll,char name[])
{
    struct node *newnode = createnode(roll,name);
    newnode->next = head;
    head = newnode;
}

// insert in middle after a roll
void insertmiddle(int afterroll,int roll,char name[])
{
    struct node *temp = head;

    while(temp != NULL && temp->roll != afterroll)
        temp = temp->next;

    if(temp == NULL) return;

    struct node *newnode = createnode(roll,name);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletemiddle(int roll)
{
    struct node *temp = head;

    /* find the node */
    while(temp != NULL && temp->roll != roll)
    {
        temp = temp->next;
    }

    if(temp == NULL)
        return;   // not found

    if(temp->next == NULL)
    {
        deletelast();
        return;
    }

    if(temp->prev == NULL)
    {
        deletefront();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}



int main()
{
    insertlast(22,"ariyan");
    insertlast(32,"zariyan");
    insertlast(42,"maariyam");

    printf("\nprinting from front\n");
    printfront();

    printf("\ndelete from front\n");
    deletefront();
    printfront();

    printf("\ndelete from last\n");
    deletelast();
    printfront();

    printf("\ninserting from front\n");
    insertfront(42,"maariyam");
    printfront();

    printf("\ninserting in the middle\n");
    insertmiddle(42,72,"middleNode");
    printfront();

    deletemiddle(72);

printf("\nAfter delete middle\n");
printfront();
}
