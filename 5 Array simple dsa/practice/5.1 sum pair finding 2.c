//find the total number of pair in the array whose sum is equal to the given value of  n (2) intgreating(bee1173)
#include<stdio.h>
int main (){
    int n,x[10],f;
    scanf("%d", &n);
    x[0]=n;

    printf("enter the sum : ");
    scanf("%d",&f);
//printing numbers auto
    for (int i = 0; i < 10; i++)
    {
        if(i>0)
        x[i]=x[i-1]*2;
        
    printf("N[%d] = %d\n",i,x[i]);
    }
    //finding pairs
    int pair=0;
for (int i = 0; i < 10; i++)
{
    for (int j = i+1; j < 10; j++)
    {
        if (x[i]+x[j]==f)
        {
            pair++;
            printf("summing with %d,%d\n",x[i],x[j]);
        }
        
    }
    
}
printf("\npairs = %d",pair);

}