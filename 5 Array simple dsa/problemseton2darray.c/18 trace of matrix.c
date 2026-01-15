#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];
    int trace = 0;

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Trace = sum of diagonal (i == j)
    for (int i = 0; i < m && i < n; i++) {
        trace += a[i][i];
    }

    printf("Trace: %d\n", trace);

    return 0;
}
