#include<stdio.h>
#include<string.h> // Necessary for strlen()

typedef struct student
{
    char name[50];
    int n;
} stu;

void scan(stu s1[50], int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("enter number %d student name : ", i + 1);
        fgets(s1[i].name, 50, stdin);
    }
}

void print(stu s1[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        // strlen calculates how many characters are in the string
        int letter_count = strlen(s1[i].name);

        // fgets includes the '\n' (Enter key) at the end. 
        // We subtract 1 so we only count the actual letters.
        if (s1[i].name[letter_count - 1] == '\n') {
            letter_count--;
        }

        printf("Name: %s", s1[i].name);
        printf("Letter count: %d\n", letter_count);
    }
}

int main(){
    stu s1[50];
    int n;
    printf("how many students : ");
    scanf("%d", &n);
    getchar();

    scan(s1, n);
    print(s1, n);

    return 0;
}