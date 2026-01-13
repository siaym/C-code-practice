#include<stdio.h>
int main (){
char a;
printf("Enter the letter : ");
scanf("%c",&a);
if ( a>='A' && a<='Z' && a>='a'&& a<='z' )
{
  printf(" %c is an alphabet letter  ",a);
} else if (a>='0'&& a<='9')
  printf(" %c is a digit ",a);
else 
printf ("%c is a special charector  ",a);





}