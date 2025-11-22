#include <stdio.h>
int main() {
    int n,digit,rev=0;
    printf("enter the num: ");
    scanf("%d",&n);

    for(; n >0; n = n / 10) {   
        digit = n % 10;   
         rev = rev * 10 + digit;       
               
    }

    printf("Sum = %d\n", rev);
    return 0;
}
