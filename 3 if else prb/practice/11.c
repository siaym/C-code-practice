#include <stdio.h>

int main() {
    int x;
    printf("Enter the friend's position (x > 0): ");
    scanf("%d", &x);

    int steps = x / 5;
    if (x % 5 != 0) {
        steps = steps + 1;
    }

    printf("Minimum number of steps: %d\n", steps);

    return 0;
}
