#include <stdio.h>

int main() {
    float A, B;      
    double C, D;     

    
    scanf("%f %f", &A, &B);
    scanf("%lf %lf", &C, &D);

    printf("A = %.6f, B = %.6f\n", A, B);
    printf("C = %.6f, D = %.6f\n", C, D);

   
    printf("A = %.1f, B = %.1f\n", A, B);
    printf("C = %.1f, D = %.1f\n", C, D);

   
    printf("A = %.2f, B = %.2f\n", A, B);
    printf("C = %.2f, D = %.2f\n", C, D);

 
    printf("A = %.3f, B = %.3f\n", A, B);
    printf("C = %.3f, D = %.3f\n", C, D);

    printf("A = %.3E, B = %.3E\n", A, B);
    printf("C = %.3E, D = %.3E\n", C, D);

    printf("A = %.0f, B = %.0f\n", A, B);
    printf("C = %.0f, D = %.0f\n", C, D);

    return 0;
}
