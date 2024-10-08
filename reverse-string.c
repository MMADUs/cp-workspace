#include <stdio.h>
#include <string.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        char words[1000];
        scanf("%s", words);
        int len = strlen(words);
        for (int i = 0; i < len / 2; i++) {
            char temp = words[i];
            words[i] = words[len - i - 1];
            words[len - i - 1] = temp;
        }
        printf("Case #%d : %s\n", i + 1, words);
    }
    return 0;
}