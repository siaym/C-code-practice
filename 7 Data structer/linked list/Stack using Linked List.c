#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[50];
    struct node *next;
};

struct node *top = NULL;

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
    return (top==NULL);
}

// PUSH (insert front)
void push(int roll,char name[])
{
    struct node *newnode = createnode(roll,name);
    newnode->next = top;
    top = newnode;
    printf("Pushed: %d--%s\n",roll,name);
}

// POP (delete front)
void pop()
{
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    printf("Popped: %d--%s\n",top->roll,top->name);
    top = top->next;
    free(temp);
}

// PEEK (view top)
void peek()
{
    if(isEmpty()){
        printf("Stack Empty\n");
        return;
    }
    printf("Top = %d--%s\n",top->roll,top->name);
}

// Display stack
void display()
{
    struct node *temp=top;
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