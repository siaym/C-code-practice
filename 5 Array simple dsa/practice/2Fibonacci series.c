#include<stdio.h>
int main (){
int a[30],n;
a[0]=0;
a[1]=1;
scanf("%d",&n);
for (int i = 2; i < n; i++)
{
    a[i]=a[i-1]+a[i-2];
/*a[2] = a[1] + a[0] = 1 + 0 = 1
a[3] = a[2] + a[1] = 1 + 1 = 2
a[4] = a[3] + a[2] = 2 + 1 = 3
a[5] = a[4] + a[3] = 3 + 2 = 5
a[6] = a[5] + a[4] = 5 + 3 = 8
a[7] = a[6] + a[5] = 8 + 5 = 13
...*/

}
printf("\n");
for (int i = 0; i < n; i++)
{
    printf("%d ",a[i]);
}




}