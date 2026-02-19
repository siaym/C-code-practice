#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int roll;
    float cgpa;
    char name[50];

    struct node *next,*prev;
};

struct node *head=NULL;

struct node *createnode(int roll , float cgpa , char name[] )
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->roll=roll;
    newnode->cgpa=cgpa;
    strcpy(newnode->name,name);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};


void insertlast(int roll,float cgpa,char name[] ){
    struct node *newnode=createnode(roll,cgpa,name);

    if (head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;

}

void printback(){
    struct node  *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    while (temp!=NULL)
    {
        printf("%d- %.2f- %s \n",temp->roll,temp->cgpa,temp->name);
        temp=temp->prev;
    }
    
}

int main (){

insertlast(10,3.6,"raiyan");
insertlast(20,3.6,"aiyan");
    printback();



}