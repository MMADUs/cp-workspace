#include <stdio.h>

int main() {
    // printf("%c", 97);
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int index;
        scanf("%d", &index);
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < index; j++) {
            printf("%c", j + 97);
        }
        printf("\n");
    }
    return 0;
}