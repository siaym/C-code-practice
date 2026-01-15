#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);

    if (X > Y) {
        int temp = X;
        X = Y;
        Y = temp;
    }
    for (int i = X + 1; i < Y; i++) {
        int r = i % 5;
        if (r == 2 || r == 3) {
            printf("%d\n", i);
        }
    }

    return 0;
}
