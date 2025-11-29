#include <stdio.h>

int main() {
    int m, n, count = 0;
    scanf("%d %d", &m, &n);

    int a[m][n];

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Count even numbers
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    printf("Number of even elements: %d\n", count);

    return 0;
}
