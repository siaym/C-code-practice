void count(stu s1[50], int n){
    for(int i = 0; i < n; i++){
        int letters = 0;

        for(int j = 0; s1[i].name[j] != '\0'; j++){
            if(s1[i].name[j] != '\n')
                letters++;
        }

        printf("Student %d letters : %d\n", i+1, letters);
    }
}





void count(stu s1[50], int n){
    int totalLetters = 0;

    for(int i = 0; i < n; i++){          // loop through students
        int j = 0;

        while(s1[i].name[j] != '\0'){   // loop through characters
            totalLetters++;
            j++;
        }
    }

    printf("Total letters in all names : %d\n", totalLetters);
}
