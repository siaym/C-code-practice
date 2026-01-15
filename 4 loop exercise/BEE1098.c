//not fully solved have to understand again
#include <stdio.h>

int main() {
    float I, J;
    for (I = 0; I <= 2.1; I += 0.2) {
        for (J = 1; J <= 3; J++) {
            if (I == 0 || I == 1 || I > 1.9)
                printf("I=%.0f J=%.0f\n", I, J + I);
            else
                printf("I=%.1f J=%.1f\n", I, J + I);
        }
    }
    return 0;
}
