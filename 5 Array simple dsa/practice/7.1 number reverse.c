#include<stdio.h>
int main (){
int x[8]={1,2,3,4,5,6,7,8};
int temp,i;

for ( i = 0; i <= 4; i++) // i <= 4  because we dont have rev fully just 50% can do whole  (important)
{
    temp=x[i];
    x[i]=x[8-1-i];
    x[8-1-i]=temp;
    
}
for ( i = 0; i <= 7; i++)
printf("%d ",x[i]);

 

}