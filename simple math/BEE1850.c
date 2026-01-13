#include <stdio.h>

int main() {
    long long a, b;
    long long sumB, sumA_1, result;

    scanf("%lld %lld", &a, &b);

    sumB = b * (b + 1) / 2;
    sumA_1 = (a - 1) * a / 2;

    result = sumB - sumA_1;

    printf("%lld\n", result);

    return 0;
}
