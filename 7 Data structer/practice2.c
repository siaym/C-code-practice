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

//firstly we create a universal node for all
struct node *createnode(int roll,char name[])
{
    struct node *newnode=malloc(sizeof(struct node ));
    newnode->roll=roll;
    strcpy(newnode->name,name );
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;

};

//insertng from last 
void insertlast(int roll,char name[]){
    struct node *newnode=createnode(roll,name);
    if (head==NULL)
    {
        /* code */ head=newnode;
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
// printing from back
void printback(){
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        /* code */temp=temp->next;

    }
    while (temp!=NULL)
    {
        /* code */ printf("%d %s \n",temp->roll,temp->name);
        temp=temp->prev;
       
    }
}
// printing from front 
void printfront(){
    struct node *temp=head;
    
    while (temp!=NULL)
    {
        /* code */ printf("%d %s \n",temp->roll,temp->name);
        temp=temp->next;
    }
    
}

int main (){
    printf("printing from back \n");
insertlast(34,"ariyen");
insertlast(334,"aziyen");
insertlast(434,"raziyen");
printback();
printf("\nprinting from front \n");
printfront();
}


void deletefront()
{
    if(head == NULL)
        return;

    struct node *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}


void deleteback()
{
    if(head == NULL)
        return;

    struct node *temp = head;

    if(temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    free(temp);
}


void insertfront(int roll, char name[])
{
    struct node *newnode = createnode(roll, name);

    newnode->next = head;

    if(head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}

void insertmiddle(int afterRoll, int roll, char name[])
{
    struct node *temp = head;

    while(temp != NULL && temp->roll != afterRoll)
    {
        temp = temp->next;
    }

    if(temp == NULL)
        return;   // position not found

    struct node *newnode = createnode(roll, name);

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

