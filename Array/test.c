#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int largest = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] < largest) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        printf("There is no second largest element.");
    else
        printf("The second largest element is: %d", second);

    return 0;
}