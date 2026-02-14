#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
    int roll;
    char name[50];
    float cgpa;
    struct stu *next;
} stu;

stu* createNode(int r, char n[], float c){
    stu* newNode = (stu*)malloc(sizeof(stu));
    newNode->roll = r;
    strcpy(newNode->name, n);
    newNode->cgpa = c;
    newNode->next = NULL;
    return newNode;
}

void printList(stu* head){
    stu* temp = head;
    while(temp != NULL){
        printf("Roll: %d, Name: %s, CGPA: %.2f\n",
               temp->roll, temp->name, temp->cgpa);
        temp = temp->next;
    }
}

int main(){
    stu *head = NULL;

    head = createNode(100,"A",3.40);
    head->next = createNode(102,"B",3.70);
    head->next->next = createNode(105,"C",3.10);

    printList(head);
    return 0;
}
