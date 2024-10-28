#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int dimension;
        scanf("%d", &dimension);
        for (int i = 1; i <= dimension; i++) {
            for (int j = 1; j <= dimension - i; j++) {
                printf(" ");
            }
            for (int k = 1; k <= (2 * i - 1); k++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}