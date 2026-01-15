//find the total number of pair in the array whose sum is equal to the given value of  n
#include<stdio.h>
int main (){
    int n,x[]={1,2,3,4,5,6,7,8};
    scanf("%d",&n);
    int pair=0;
    for (int  i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 8; j++)
        {
            if (x[i]+x[j]==n)
            {
                pair++;
                printf("number are %d,%d\n",x[i],x[j]);
            }
            
        }
        
    }
    printf(" pair %d",pair);
}