#include <stdio.h>
#include <string.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        char words[1000];
        scanf("%s", words);
        printf("Case %d: ", i + 1);
        for (int j = 0; j < strlen(words); j++) {
            printf("%d", words[j]);
            if (j < strlen(words) - 1) {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
