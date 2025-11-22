#include<stdio.h>
int main (){
int a;
printf("Enter the  number : ");
scanf("%d",&a);

if (  a%4==0 && a%400==0 )
{
  printf(" %d is divisible by both 4 and 400 ",a);
} else 
printf(" %d isnt  divisible by both 4 and 400 ",a);





}