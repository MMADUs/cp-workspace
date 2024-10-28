#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (long long int i = 0; i < total; i++) {
        int dimension;
        scanf("%d", &dimension);
        // Declare a 2D array for storing the values
        long long int value[dimension][dimension];
        // Input the y-dimension (rows)
        for (int j = 0; j < dimension; j++) {
            // Input the x-dimension (columns)
            for (int k = 0; k < dimension; k++) {
                scanf("%lld", &value[j][k]);  // Store each value in the 2D array
            }
        }
        // calculate
        printf("Case #%lld: ", i + 1);
        for (int x = 0; x < dimension; x++) {
            long long int res = 0;
            for (int y = 0; y < dimension; y++) {
                res += value[y][x];
            }
            printf("%lld", res);
            if (x!=dimension-1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}