#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[50];
    struct node *next, *prev;
};

struct node *head = NULL;
struct node *createnode(int roll, char name[])
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->roll = roll;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void insertlast(int roll, char name[])
{
    struct node *newnode = createnode(roll, name);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void printback()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d--%s\n", temp->roll, temp->name);
        temp = temp->prev;
    }
}

void printfront(){

struct node *temp=head;
   
    while (temp!=NULL)
    {
        printf("%d--%s\n", temp->roll, temp->name);
        temp=temp->next;
    }
    
}

void deletefront(){
    struct node *temp=head;
    head=head->next;
    if (head!=NULL)
    {
        head->prev=NULL;
    }
    free(temp);

}

void deletelast(){
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        
    }
    
}

int main()
{

    insertlast(22, "ariyan");
    insertlast(32, "zariyan");
    insertlast(42, "maariyam");

    printf("\nprinting from back\n");

    printback();

    printf("\nprinting from front\n");

    printfront();

        printf("\ndelete  from front\n");
        deletefront();
        printfront();


}
