#include<stdio.h>
#include<string.h>

typedef struct student 
{
    int house,block;
    char city[30],state[30];
} stu;

void scan(stu *s1){
    scanf("%d %d %s %s",&s1->house,&s1->block,s1->city,s1->state);
};

void print (stu s1){
    printf("%d %d %s %s",s1.house,s1.block,s1.city,s1.state);
};


int main (){
stu s1;
scan(&s1);
print(s1);
}