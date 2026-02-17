// create a function of create node for easy code 

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

/* ---------- Create Node ---------- */
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

/* ---------- Insert Last (Used in Q1) ---------- */
void insertLast(int roll,char name[],float cgpa)
{
    struct node *newnode = createNode(roll,name,cgpa);

    if(head==NULL)
    {
        head=newnode;
        return;
    }

    struct node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;
}

/* ---------- Q2(b) Insert at Beginning ---------- */
void insertFirst(int roll,char name[],float cgpa)
{
    struct node *newnode=createNode(roll,name,cgpa);

    if(head!=NULL)
        head->prev=newnode;

    newnode->next=head;
    head=newnode;
}

/* ---------- Q2(c) Delete Last ---------- */
void deleteLast()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    /* only one node */
    if(temp->prev==NULL)
    {
        free(temp);
        head=NULL;
        return;
    }

    temp->prev->next=NULL;
    free(temp);
}

/* ---------- Q2(a) Print From Backend ---------- */
void printFromBack()
{
    if(head==NULL) return;

    struct node *temp=head;

    /* go to last node */
    while(temp->next!=NULL)
        temp=temp->next;

    /* traverse backward */
    while(temp!=NULL)
    {
        printf("Roll:%d  Name:%s  CGPA:%.2f\n",
        temp->roll,temp->name,temp->cgpa);

        temp=temp->prev;
    }
}

int main()
{
    /* Q1: three students in ascending order */
    insertLast(100,"Ayan",3.20);
    insertLast(102,"Rafi",3.80);
    insertLast(105,"Nila",3.50);

    printf("\nQ2(a) Print from backend:\n");
    printFromBack();

    printf("\nQ2(b) Insert at beginning:\n");
    insertFirst(101,"Maruf",3.56);
    printFromBack();

    printf("\nQ2(c) Delete last:\n");
    deleteLast();
    printFromBack();

    return 0;
}
