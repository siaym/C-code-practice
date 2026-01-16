#include<stdio.h>
int main (){
  int arr[5];
  printf("enter numbers: ");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d",&arr[i]);
  }
  //finding 1st max
  int max=arr[0];
   for (int i = 0; i < 5; i++)
  {
        if (max<arr[i])
        {
            max=arr[i];
        }
    
  }
  printf("1st max numb %d\n",max);

    //finding 2nd max
    int smax=arr[0];
   for (int i = 0; i < 5; i++)
  {
        if (arr[i]!=max && smax<arr[i])
        {
            smax=arr[i];
        }
    
  }
    printf("2nd max numb %d\n",smax);

}