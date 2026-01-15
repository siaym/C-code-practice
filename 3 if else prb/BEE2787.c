#include <stdio.h>

int main() {
    int L, C;
    scanf("%d", &L);
    scanf("%d", &C);

    if ((L + C) % 2 == 0) {
        printf("1\n");  // Whiteee
    } else {
        printf("0\n");  // Blackkk
    }

    return 0;
}
