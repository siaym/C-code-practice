#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LEN 1024

// Sample texts to type
const char *texts[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming in C is powerful and efficient.",
    "Typing speed improves with practice and focus.",
    "A journey of a thousand miles begins with a single step.",
    "Debugging is twice as hard as writing the code in the first place."
};

int getRandomIndex(int n) {
    return rand() % n;
}

// Remove trailing newline from fgets
void removeNewline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

// Calculate accuracy (percentage of matching characters)
double calculateAccuracy(const char *original, const char *typed) {
    int lenOrig = strlen(original);
    int lenTyped = strlen(typed);
    int minLen = (lenOrig < lenTyped) ? lenOrig : lenTyped;

    int correct = 0;
    for (int i = 0; i < minLen; i++) {
        if (original[i] == typed[i]) {
            correct++;
        }
    }

    return (lenOrig == 0) ? 0.0 : (correct * 100.0) / lenOrig;
}

// Count words in a string (simple space-based)
int countWords(const char *s) {
    int count = 0;
    int inWord = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            if (!inWord) {
                inWord = 1;
                count++;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

int main() {
    char typed[MAX_TEXT_LEN];
    char name[50];

    srand((unsigned int)time(NULL));

    printf("=== Typing Speed Test ===\n\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    removeNewline(name);

    int textCount = sizeof(texts) / sizeof(texts[0]);
    int idx = getRandomIndex(textCount);
    const char *target = texts[idx];

    printf("\nType the following text exactly as shown:\n\n");
    printf("\"%s\"\n\n", target);
    printf("Press ENTER when you are ready to start...");
    getchar(); // wait for user to press enter

    printf("\nStart typing below and press ENTER when done:\n\n");

    clock_t start = clock();
    fgets(typed, sizeof(typed), stdin);
    clock_t end = clock();

    removeNewline(typed);

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    double minutes = seconds / 60.0;

    int charsTyped = strlen(typed);
    int wordsTyped = countWords(typed);
    double accuracy = calculateAccuracy(target, typed);

    double wpm = (minutes > 0) ? (wordsTyped / minutes) : 0.0;
    double cpm = (minutes > 0) ? (charsTyped / minutes) : 0.0;

    printf("\n=== Results for %s ===\n", name);
    printf("Time taken      : %.2f seconds\n", seconds);
    printf("Characters typed: %d\n", charsTyped);
    printf("Words typed     : %d\n", wordsTyped);
    printf("Accuracy        : %.2f %%\n", accuracy);
    printf("WPM             : %.2f\n", wpm);
    printf("CPM             : %.2f\n", cpm);

    // Save results to file
    FILE *fp = fopen("results.txt", "a");
    if (fp == NULL) {
        printf("\n[!] Could not open results.txt for writing.\n");
    } else {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char timeStr[64];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", t);

        fprintf(fp, "%s | Time: %.2fs | WPM: %.2f | CPM: %.2f | Accuracy: %.2f%% | %s\n",
                name, seconds, wpm, cpm, accuracy, timeStr);

        fclose(fp);
        printf("\n[+] Result saved to results.txt\n");
    }

    printf("\nPress ENTER to exit...");
    getchar();
    return 0;
}
