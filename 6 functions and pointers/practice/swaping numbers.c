//swaping numbers without using a third variable 

#include<stdio.h>
void  swap(int a , int b){
    a=a+b;
    b=a-b;
    a=a-b;

    printf("\nafter swaping : %d %d",a,b);

}
int main (){

    int x,y;
    scanf("%d %d", &x, &y);
    printf("before swaping numbers are : %d %d",x,y);
     swap(x,y);
    
}
