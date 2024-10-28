#include <stdio.h>

int main() {
    char word1[20];
    char word2[20];
    char word3[20];
    scanf("%s", word1);
    scanf("%s", word2);
    scanf("%s", word3);
    printf("%s %s %s", word3, word2, word1);
    return 0;
}