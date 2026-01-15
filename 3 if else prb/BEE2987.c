#include <stdio.h>

int main() {
    char L;
    scanf("%c", &L);

    int position = L - 'A' + 1;

    printf("%d\n", position);

    return 0;
}
