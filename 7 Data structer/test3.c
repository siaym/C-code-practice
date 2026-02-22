#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int roll;
    char name[50];
    struct node *prev,*next;
};
struct node *head=NULL;
struct node *createnode(int roll,char name[])
{
    /* data */ struct node *newnode=malloc(sizeof(struct node));
    newnode->roll=roll;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode ;
};
void insertlast(int roll,char name[]){
    struct node *newnode=createnode(roll,name);
    struct node *temp=head;
    if (head==NULL)
    {
        /* code */head=newnode;
        return;
    }
    
    while (temp->next!=NULL)
    {
        /* code */ temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
 void printback(){
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    while (temp!=NULL)
    {
        /* code */printf("%d--%s\n", temp->roll, temp->name);
        temp = temp->prev;
    }
    
}
 void printfront(){
    struct node *temp=head;
    while (temp!=NULL)
    {
        /* code */printf("%d--%s\n", temp->roll, temp->name);
        temp = temp->next;
    }

 }
 void deletefront(){
    struct node *temp=head;
    head=head->next;
    if (head!=NULL)
    {
        /* code */  head->prev=NULL;                      
    }
    free(temp);
 }
void  deletelast(){
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        /* code */temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    
}
void insertfront(int roll,char name[]){
struct node *newnode=createnode(roll,name);
    struct node *temp=head;

}
void insertmiddle(int afterroll,int roll,int name[]){
    struct node *temp=head;
    while (temp!=NULL && temp->next!=afterroll)
    {
        /* code */temp=temp->next;
    }
    struct node *newnode=createnode(roll,name);
    newnode->next=temp->next;
    newnode->prev=temp;
    while (temp!=NULL)
    {
        /* code */
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

    printf("\ndelete  from last\n");
    deletelast();
    printfront();

        printf("\ninserting  from front\n");

    insertfront(42, "maariyam");
    printfront();
printf("\ninserting in the middle \n");
    insertmiddle(42,72,"middleNode"); 
printfront();
}

