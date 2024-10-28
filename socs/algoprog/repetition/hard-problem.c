#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int total;
        scanf("%d", &total);
        char question[total + 1];
        char answer[total + 1];
        scanf("%s", question);
        scanf("%s", answer);
        int count = 0;
        for (int j = 0; j < total; j++) {
            if (question[j] == answer[j]) {
                count++;
            }
        }
        const int final = count * 100 / total;
        printf("Case #%d: %d\n", i + 1, final);
    }
    return 0;
}