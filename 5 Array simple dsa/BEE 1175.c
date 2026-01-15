#include<stdio.h>
int main (){
    int x[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d",&x[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        int temp=x[i];
        x[i]=x[19-i];
        x[19-i]=temp;

    }
for (int i = 0; i < 20; i++){
    printf("N[%d] = %d\n",i,x[i]);
}    
    

}