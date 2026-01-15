#include <stdio.h>

int main() {
    int n, sum = 0, digit;

    printf("Enter a Number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;   // get the last digit
        sum = sum + digit; // add it to sum
        n = n / 10;       // remove the last digit
    }

    printf("Sum = %d\n", sum);

    return 0;
}

/*#include <stdio.h>

int main() {
    int n, sum = 0, digit;

    printf("Enter a Number: ");
    scanf("%d", &n);

    for(; n > 0; n = n / 10) {   // loop runs as long as n > 0
        digit = n % 10;          // get the last digit
        sum = sum + digit;       // add it to sum
    }

    printf("Sum = %d\n", sum);

    return 0;
}*/
