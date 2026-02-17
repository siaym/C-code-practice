#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;   // global head

// create node at end (helper function)
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

// delete first node
void deleteatfirst()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *k = head;   // save first node
    head = head->next;       // move head forward
    free(k);                 // delete old node
}

// print list
void printList()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main ()
{
    int n = 10;

    // create list: 1 2 3 ... 10
    for(int i=1;i<=n;i++)
        insertlast(i);

    printf("Before delete:\n");
    printList();

    deleteatfirst();

    printf("After delete:\n");
    printList();

    return 0;
}
