#include <stdio.h>
int main() {
    int n,digit,rev=0;
    printf("enter the num: ");
    scanf("%d",&n);

    int original=n;

    for(; n >0; n = n / 10) {   
        digit = n % 10;   
         rev = rev * 10 + digit;       
               
    }

    printf("reverse = %d\n", rev);

    if (rev==original)

    {
        printf("the number is pali");
    }else 
    printf("the number isnt pali");
    
    return 0;
}
