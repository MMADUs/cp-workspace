#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int dimension;
        scanf("%d", &dimension);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < dimension; j++) {
            for (int k = 0; k < dimension; k++) {
                if (k >= dimension - 1 - j) {
                    if (dimension % 2 != 0) {
                        if ((dimension - 1 - k - j) % 2 == 0) {
                            printf("*");
                        } else {
                            printf("#");
                        }
                    } else {
                        if ((dimension - 1 - k - j) % 2 == 0) {
                            printf("#");
                        } else {
                            printf("*");
                        }
                    }
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}