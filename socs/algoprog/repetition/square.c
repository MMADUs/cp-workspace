#include <stdio.h>

int main() {
    int dimension;
    scanf("%d", &dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}