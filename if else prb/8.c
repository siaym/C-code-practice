#include<stdio.h>
int main (){
char a;
printf("Enter the letter : ");
scanf("%c",&a);
if ( a>='A' && a<='Z' )
{
  printf(" %c is an uppercase letter  ",a);
} else if (a>='a'&& a<='z')
  printf(" %c is a lowercase letter  ",a);
else 
printf ("%c isnt a alphabeet  letter ",a);





}