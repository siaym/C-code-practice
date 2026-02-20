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
    if (head!=NULL)
    {
        /* code */ 
    }
    
}

int main(){
    insertlast(32,"ariyan");
    insertlast(42,"zriyan");
    insertlast(52,"mriyan");
    printback();
printf("\n");
printfront();
printf("\n");
deletelast();
printfront();

}