#include<stdio.h>
int main (){
    int n[]={1,2,4,3,6,7,8,9};
    int i,sumeven=0,sumodd=0;
    
    for ( i = 0; i < 8; i++)
    {
        if (n[i]%2==0)
        {
            sumeven=sumeven+n[i];
        }else
        sumodd=sumodd+n[i];
        

    }
    printf("sum of even : %d\n",sumeven);
    printf("sum of odd : %d\n",sumodd);
    printf("sum of evenodd : %d\n",sumeven+sumodd);
    

}