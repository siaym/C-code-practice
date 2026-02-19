#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int roll;
    char name[50];
    float cgpa;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int roll,char name[],float cgpa)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->roll = roll;
    strcpy(newnode->name,name);
    newnode->cgpa = cgpa;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

/* insert last */
void insertLast(int roll,char name[],float cgpa)
{
    struct node *newnode=createNode(roll,name,cgpa);

    if(head==NULL){
        head=newnode;
        return;
    }

    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;
}

/* insert beginning */
void insertFirst(int roll,char name[],float cgpa)
{
    struct node *newnode=createNode(roll,name,cgpa);
    newnode->next=head;
    if(head) head->prev=newnode;
    head=newnode;
}

/* delete last */
void deleteLast()
{
    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    if(temp->prev)
        temp->prev->next=NULL;
    else
        head=NULL;

    free(temp);
}

/* print from back */
void printBack()
{
    struct node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    while(temp!=NULL){
        printf("%d %s %.2f\n",temp->roll,temp->name,temp->cgpa);
        temp=temp->prev;
    }
}

int main()
{
    insertLast(100,"Ayan",3.20);
    insertLast(102,"Rafi",3.80);
    insertLast(105,"Nila",3.50);

    printBack();

    insertFirst(101,"Maruf",3.56);
    printBack();

    deleteLast();
    printBack();
}
