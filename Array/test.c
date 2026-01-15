#include<stdio.h>
int main (){
    int n;
    printf("ENter the total number : ");
    scanf("%d", &n);
        int arr[n];

    printf("ENter the numbers : ");

for (int  i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}
printf("\nthe numbers are : ");
for (int  i = 0; i < n; i++)
{
    printf("%d ",arr[i]);
}
//sum
int sum;
for (int  i = 0; i < n; i++)
{
     sum=sum+arr[i];
}
printf("\nsum of the numbers : %d",sum);

//minus
int min=0;
for (int  i = 0; i < n-2; i++)
{
     min=(n-2)-arr[0];
     
}
printf("\n min of the numbers : %d",min);


}