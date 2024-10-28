#include <stdio.h>

int main() {
    int dim, jump;
    scanf("%d %d", &dim, &jump);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if ((i + 1) % jump != 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if ((j + 1) % jump != 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}
