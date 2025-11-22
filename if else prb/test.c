#include <stdio.h>

int main() {
    int n,count=0;

    printf("Enter a number: ");
    scanf("%d", &n);

  for (; n != 0; n = n / 10) {
            count++;
        }

  printf("the number : %d",count);
   
          


    return 0;
}
