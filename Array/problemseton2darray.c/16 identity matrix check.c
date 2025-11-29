#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    int flag = 1;   // assume identity

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check identity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // On diagonal → must be 1
            if (i == j && a[i][j] != 1)
                flag = 0;

            // Off diagonal → must be 0
            if (i != j && a[i][j] != 0)
                flag = 0;
        }
    }

    if (flag)
        printf("Matrix1 is an IDENTITY MATRIX.\n");
    else
        printf("Matrix1 is NOT an identity matrix.\n");

    return 0;
}
