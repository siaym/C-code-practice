#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void insertfront(node *header, int data);
void insertlast(node *header, int data);
void insertat(node *header, int data, int index);
void insertbeforevalue(node *header, int data, int value);

int main()
{
    struct node *header;
    header = (struct node *)malloc(sizeof(struct node));
    struct node *header;
    header = (struct node *)malloc(sizeof(struct node));
    if (header == NULL)
    {
        printf("memory not allocated");
        return 0;
    }

    header->data = __INT_MAX__;
    header->link = NULL; // sinngly link list

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int number= rand()%1000;
        insertlast(header,number);
    }
    

}
// header-newnode-n1-n2-n3-
void insertfront(node *header, int data);
{
    node *newnode = (struct node *)malloc(sizeof(struct node))

        if (header == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    else
    {
        newnode->data = data;
        newnode->link = header->link;
        header->link = newnode;
    }
}

// header-n1-n2-n3-newnode

void insertlast(node *header, int data);
{
    node *ptr = header;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    node *newnode = (struct node *)malloc(sizeof(struct node)) if (header == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    else
    {
        newnode->data = data;
        newnode->link = ptr->link;
        header->link = newnode;
    }
}

// header-n0-n1-n2-newnode-n3-n4-n5-newnode
void insertat(node *header, int data, int index);
{
    node *ptr = header;

    int indexcheck = 0;

    while (indexcheck < index && ptr->link != NULL)
    {
        indexcheck++;
        ptr = ptr->link;
    }
    if (indexcheck + 1 != index)
    {
        printf("memory not allocated");
    }
    node *newnode = (struct node *)malloc(sizeof(struct node)) if (header == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    else
    {
        newnode->data = data;
        newnode->link = ptr->link;
        header->link = newnode;
    }
}

// void insertbeforevalue(node *header, int data, int value);
// {
//     int index=searchindexofvalue(header,value);
//     insertat(header,data,index);
// }