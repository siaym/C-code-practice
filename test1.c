#include <stdio.h>
#include <string.h>

struct student {
    int roll;
    float cgpa;
    char name[50];
};

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Roll: ");
        scanf("%d", &s[i].roll);

        printf("CGPA: ");
        scanf("%f", &s[i].cgpa);

        printf("Name: ");
        scanf("%s", s[i].name);
    }

    printf("\n--- Student List ---\n");

    for (i = 0; i < n; i++) {
        printf("Student %d: Roll=%d CGPA=%.2f Name=%s\n",
               i + 1,
               s[i].roll,
               s[i].cgpa,
               s[i].name);
    }

    return 0;
}
