#include<stdio.h>
int main (){
    int arr[]={1,3,4,5,9};
    int n=1,count=0;
    for (int  i = 0; i <5; i++)
    {
        if (n<arr[i])
        {
            count++;
            // printf("%d",arr[i]);
        }
        
    }
    printf("%d",count);
    
    

}