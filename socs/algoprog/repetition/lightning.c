#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        int value[5+1];
        for (int j = 0; j < 5+1; j++) {
            scanf("%d", &value[j]);
        }
        printf("Case #%d: ", i + 1);
        for (int k = 0; k < value[0]; k++) {
            printf("a");
        }
        for (int k = 0; k < value[1]; k++) {
            printf("s");
        }
        for (int k = 0; k < value[2]; k++) {
            printf("h");
        }
        for (int k = 0; k < value[3]; k++) {
            printf("i");
        }
        for (int k = 0; k < value[4]; k++) {
            printf("a");
        }
        for (int k = 0; k < value[5]; k++) {
            printf("p");
        }
        printf("\n");
    }
    return 0;
}