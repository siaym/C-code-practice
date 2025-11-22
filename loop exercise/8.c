 #include<stdio.h>
 int main ()
 {
int n,count=0;
printf("enter the number = ");
scanf("%d",&n);

for ( ; n > 0; n=n/10)
{
  count++;
}
printf("total digits = %d",count);

 }