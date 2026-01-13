#include<stdio.h>
int main (){
int a;
printf("Enter the  year : ");
scanf("%d",&a);

if ( ( a % 400 == 0) || (a % 4 == 0 && a % 100 != 0) )
{
  printf(" %d is a leap year  ",a);
} else 
printf(" %d isnt  a leap year  ",a);





}