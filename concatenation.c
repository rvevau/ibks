#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeWords(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int maxSize = len1 + len2 + 1;

    char* merged = (char*)malloc(maxSize * sizeof(char));
    int commonLen = 0;

    for (int i = 0; i < len1; i++) {
        int match = 1;
        for (int j = 0; j < len1 - i; j++) {
            if (word1[i + j] != word2[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            commonLen = len1 - i;
            break;
        }
    }

    strncpy(merged, word1, len1 - commonLen);
    merged[len1 - commonLen] = '\0';
    strcat(merged, word2);

    return merged;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char word1[33], word2[33];
        scanf("%s %s", word1, word2);
        getchar();

        char* merged = mergeWords(word1, word2);
        printf("%s\n", merged);
        free(merged);
    }

    return 0;
}
