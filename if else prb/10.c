#include<stdio.h>
int main (){
int a;
printf("Enter the  number : ");
scanf("%d",&a);

if ( a==1 )
{
  printf(" %d is saturday ",a);
} else if (a==2){
printf(" %d is sunday ",a);}
else if (a==3){
printf(" %d is monday ",a);}
else if (a==4){
printf(" %d is tuesday ",a);}
else if (a==5){
printf(" %d is wednesday ",a);}
else if (a==6){
printf(" %d is thursday ",a);}
else if (a==7){
printf(" %d is friday ",a);}
else 
printf("%d is nt a day ",a );


}