#include<stdio.h>
typedef struct student
{
    char name[50];
    int n;
} stu;

void scan(stu s1[50] ,int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("enter number  %d student name : ",i+1);
        fgets(s1[i].name,50,stdin);
    }
    
}

void print(stu s1[50], int n)
{
    // int count=0;
    for (int i = 0; i < n; i++)
    {
        printf("%s",s1[i].name);
        // count++;
        //  printf("%d\n",count);
    }
}

void count(stu s1[50],int n){
    for (int i = 0; i < n; i++)
    {
     int   word=0;
        for (int j = 0; s1[i].name[j]!='\0'; j++)
        {
            word++;
        }
        printf("for number %d student : %d\n",i+1,word-1);
        
    }
    
}

int main(){
stu s1[50];
int n;
printf("how many students : ");
scanf("%d",&n);
getchar();

scan(s1,n);
print(s1,n);
count(s1,n);
}