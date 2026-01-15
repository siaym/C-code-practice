#include <stdio.h>

int main() {
    int cards[5];


    for (int i = 0; i < 5; i++) {
        scanf("%d", &cards[i]);
    }

    if (cards[0] < cards[1] && cards[1] < cards[2] && cards[2] < cards[3] && cards[3] < cards[4]) {
        printf("C\n"); 
    }
    else if (cards[0] > cards[1] && cards[1] > cards[2] && cards[2] > cards[3] && cards[3] > cards[4]) {
        printf("D\n"); 
    }

    else {
        printf("N\n"); 
    }

    return 0;
}
