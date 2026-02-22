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

// create node
struct node *createnode(int roll,char name[])
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->roll = roll;
    strcpy(newnode->name,name);
    newnode->next = NULL;
    return newnode;
}

// isEmpty
int isEmpty()
{
    return (head==NULL);
}

// PUSH (insert front)
void push(int roll,char name[])
{
    struct node *newnode = createnode(roll,name);
    newnode->next = head;
    head = newnode;
    printf("Pushed: %d--%s\n",roll,name);
}

// POP (delete front)
void pop()
{
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = head;
    printf("Popped: %d--%s\n",head->roll,head->name);
    head = head->next;
    free(temp);
}

// PEEK (view head)
void peek()
{
    if(isEmpty()){
        printf("Stack Empty\n");
        return;
    }
    printf("head = %d--%s\n",head->roll,head->name);
}

// Display stack
void display()
{
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d--%s\n",temp->roll,temp->name);
        temp=temp->next;
    }
}

int main()
{
    push(22,"ariyan");
    push(32,"zariyan");
    push(42,"maariyam");

    printf("\nStack Elements:\n");
    display();

    peek();

    printf("\nAfter Pop:\n");
    pop();
    display();

    return 0;
}