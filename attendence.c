#include <stdio.h>

int main() {
    int dimension;
    scanf("%d", &dimension);
    int value[dimension][dimension];
    // Input the y-dimension (rows)
    for (int j = 0; j < dimension; j++) {
        // Input the x-dimension (columns)
        for (int k = 0; k < dimension; k++) {
            scanf("%d", &value[j][k]);  // Store each value in the 2D array
        }
    }
    // validate
    int spectator = 0;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (value[i][j] == 0) {
                spectator++;
            }
        }
    }
    printf("%d\n", spectator);
    return 0;
}