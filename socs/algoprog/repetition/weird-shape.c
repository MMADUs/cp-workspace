#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int dimension;
        scanf("%d", &dimension);
        for (int j = 0; j < dimension; j++) {
            for (int k = 0; k < dimension; k++) {
                if (k == 0 || k == dimension - 1 || j == 0 || j == dimension - 1 || k == dimension - 1 - j || k == j) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}