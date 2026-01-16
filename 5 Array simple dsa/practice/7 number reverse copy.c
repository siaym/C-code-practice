#include<stdio.h>
int main (){
int x[7]={1,2,3,4,5,6,7};
int y[7],i;
for ( i = 0; i <= 7; i++)
{
    y[i]=x[6-i];
}

for ( i = 0; i <= 7; i++)
{
printf("%d ",y[i]);
}

 

}