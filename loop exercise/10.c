#include<stdio.h>
int main (){
    int x,fd,ld,sum;//fd=first digit ld = last digit 
    scanf("%d", &x);

    ld=x%10;
    for (fd=x;fd>=10;fd=fd/10){

    }
    sum=fd+ld;
    printf("sum=%d",sum);


}