#include<stdio.h>
int main (){
    int n,x[10];
    scanf("%d", &n);
x[0]=n;
    for (int i = 0; i < 10; i++)
    {
        if(i>0)
        x[i]=x[i-1]*2;
        

    printf("N[%d] = %d\n",i,x[i]);

    }
    
}