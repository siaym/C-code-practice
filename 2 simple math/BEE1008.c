#include <stdio.h>

int main() {
    int A;
    float B, C, salary;

    scanf("%d %f %f", &A, &B, &C);

    salary = B * C;

    printf("NUMBER = %d\n", A);
    printf("SALARY = U$ %.2f\n", salary);

    return 0;
}
