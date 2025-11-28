#include<stdio.h>
int main (){
int a[100],min,n,i;
printf("how many numbers : ");
scanf("%d",&n);
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
 min=a[0];
 for ( i = 1; i < n; i++)
 {
    if (min>a[i])
    {
        min=a[i];
    }
    /*if (max<a[i]) //for max number rest same
    {
        min=a[i];
    }*/


}                printf("%d is the minimum number ",min);

 

}