#include<stdio.h>

int main() {
    int num = 10;
    int *ptr;

    ptr = &num;              // FIX: initialize pointer before dereferencing
    *ptr = num;

    num = 27;                // FIX: removed redeclaration, just assign value

    printf("Value of num using pointer: %d\n", *ptr);  // FIX: *num → *ptr

    int arr[3] = {1, 2, 3};

    printf("Array third value: %d\n", arr[2]);         // FIX: arr[3] → arr[2]

    printf("Pointer address in Hexadecimal: %p\n", (void*)ptr); // FIX: %d → %p

    return 0;                // FIX: return int, not float
}
