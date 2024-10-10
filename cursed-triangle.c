#include <stdio.h>

int main() {
    int total, dimension;
    scanf("%d %d", &total, &dimension);
    for (int i = 0; i < total; i++) {
        for (int i = 1; i <= dimension; i++) {
            for (int j = 1; j <= dimension - i; j++) {
                printf(" ");
            }
            for (int k = 1; k <= i; k++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
