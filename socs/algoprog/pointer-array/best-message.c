#include <stdio.h>
#include <string.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        char sentence[1000+1];
        scanf("%s", sentence);
        int len = strlen(sentence);
        int key[len];
        for (int j = 0; j < len; j++) {
            if(sentence[j] >= 'A' && sentence[j] <= 'D') {
                if (sentence[j] == 'A') {
                    key[j] = 0;
                } else {
                    key[j] = sentence[j] - 'A';
                }
                sentence[j] = 'A';
            } else if(sentence[j] >= 'E' && sentence[j] <= 'H') {
                if (sentence[j] == 'E') {
                    key[j] = 0;
                } else {
                    key[j] = sentence[j] - 'E';
                }
                sentence[j] = 'E';
            } else if(sentence[j] >= 'I' && sentence[j] <= 'N') {
                if (sentence[j] == 'I') {
                    key[j] = 0;
                } else {
                    key[j] = sentence[j] - 'I';
                }
                sentence[j] = 'I';
            } else if(sentence[j] >= 'O' && sentence[j] <= 'T') {
                if (sentence[j] == 'O') {
                    key[j] = 0;
                } else {
                    key[j] = sentence[j] - 'O';
                }
                sentence[j] = 'O';
            } else if(sentence[j] >= 'U' && sentence[j] <= 'Z') {
                if (sentence[j] == 'U') {
                    key[j] = 0;
                } else {
                    key[j] = sentence[j] - 'U';
                }
                sentence[j] = 'U';
            }
        }
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < strlen(sentence); j++) {
            printf("%c", sentence[j]);
        }
        printf("\n");
        for (int j = 0; j < strlen(sentence); j++) {
            printf("%d", key[j]);
        }
        printf("\n");
    }
}
