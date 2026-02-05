#include <stdio.h>

int main() {
    char name[50];

    printf("Enter your name: ");


    fgets(name, 3, stdin);

    
    int y=345;
    



    //    gets(name);

    //  fgets(name, sizeof(name),);
    //  fgets(name,sizeof(name),stdin);



    // scanf("%s",&name);
       // reads a string including spaces

    printf("Your name is:%s\n", name);


    return 0;
}
