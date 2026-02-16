#include<stdio.h>
struct node
{
int data;
struct node *link;
};

void insertfront (node *header,int data);
void insertlast (node *header,int data);
void insertat (node *header,int data,int index);
void insertbeforevalue (node *header,int data,int value);

int main(){
struct node *header;
header =(struct node*)malloc(sizeof(struct node));
if (header==NULL)
{
    printf("memory not allocated");
    return 0;
}
header->data=__INT_MAX__;
header->link=NULL;//sinngly link list 








}