#include<stdio.h>

int main (){
    int x, y, temp; // Declare temp outside the if block for cleaner code (optional)
    
    // The main loop for processing multiple pairs
    while (1) {
        
        // 1. Read input. Using the return value for an initial check is often safer.
        if (scanf("%d %d", &x, &y) ) {
            break;
        }

        // 2. Custom Termination Condition
        if ( x <= 0 || y <= 0 ) {
            break;
        }
        
        // 3. Determine Bounds (Swap if x > y)
        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }
        
        // 4. Initialize sum for the CURRENT sequence
        int sum = 0; 
        
        // 5. Sequence Loop (Runs regardless of whether a swap occurred)
        for (int i = x; i <= y; i++) {
            printf("%d ", i);
            sum = sum + i;
        }
        
        // 6. Print the sum for the CURRENT sequence
        printf("Sum=%d\n", sum);
    }
    
    return 0;
}