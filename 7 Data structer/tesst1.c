#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insertatlast(int data){

  struct node *newnode =(struct node*)  malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;

  if (head==NULL)
  {
    head=newnode;
    return;
  }
  struct node *temp= head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }

  temp->next=newnode;
  
}
void deletefirst(){
    struct node *k=temp;
}

void print(){
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    
}

int main (){

    int n=10;
for (int   i = 1; i <= n; i++)
{
    insertatlast(i);
}
print();


}

