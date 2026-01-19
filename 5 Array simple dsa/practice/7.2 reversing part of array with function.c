#include<stdio.h>
void reverse(int arr[],int si,int ei) {
    for (int i = si ,j=ei; i < j ; i++ , j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }

}

int main (){
    int arr[]={1,2,3,4,5,6,7,8};
    int x,y;
    scanf("%d %d", &x, &y);
    reverse(arr,x,y);
    for (int i = 0; i < 8; i++)
    {
        printf("%d",arr[i]);
    }
    

    
}