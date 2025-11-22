#include<stdio.h>
int main (){
    int x,i,count=0;
    scanf("%d", &x);
    for ( ;x>0;x=x/10){
        count++;
    }
    printf("total digits : %d",count);
}