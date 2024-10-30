#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    int index[total];
    int result[total];
    for (int i = 0; i < total; i++) {
        scanf("%d", &index[i]);
    }
    for (int i = 0; i < total; i++) {
        int value;
        scanf("%d", &value);
        result[index[i]] = value;
    }
    for (int i = 0; i < total; i++) {
        printf("%d", result[i]);
        if (i != total - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
