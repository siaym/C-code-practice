#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int roll;
    char name[50];
    struct node *next,*prev;

};

struct node *head=NULL;

struct node *createnode(int roll,char name[])
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->roll=roll;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;

};

void insertlast(int roll,char name[]){
    struct node *newnode=createnode(roll,name);
    
    if (head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        /* code */ temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void printback()
{
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        /* code */  temp=temp->next;
    }
    while (temp!=NULL)
    {
        /* code */ printf("%d - %s\n",temp->roll,temp->name);
        temp=temp->prev;
    }
    
    
}
void printfront(){
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d- %s \n",temp->roll,temp->name);
        temp=temp->next;
    }
    
}

void deletelast(){
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        /* code */ temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
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
void insertfront(int roll,char name[]){
    struct node *newnode=createnode(roll,name);
    struct node *temp=head;
    newnode->next=head;
    if (head!=NULL)
    {
        /* code */head->prev=newnode;

    }
    head=newnode;
}


int main(){
    insertlast(32,"ariyan");
    insertlast(42,"zriyan");
    insertlast(52,"mriyan");
    printback();
printf("\n");
printfront();
printf("\n");

printf("deleting back \n");
deletelast();
printfront();
printf("\n");
printf("deleting front \n");
deletefront();
printfront();

printf("inserting front \n");

insertfront(62,"ratiyan");
printfront();


}