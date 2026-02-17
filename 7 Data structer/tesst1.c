#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void deleteatfirst(int data){

}

int main (){

    int n=10;


}



void insertlast(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}
