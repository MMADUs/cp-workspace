#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        int dimensionY, dimensionX;
        scanf("%d %d", &dimensionY, &dimensionX);
        long long int matrix[dimensionY][dimensionX];
        for (int j = 0; j < dimensionY; j++) {
            for (int k = 0; k < dimensionX; k++) {
                scanf("%lld", &matrix[j][k]);
            }
        }
        int maxWeight = 0;
        // Check each starting position in the first row
        for (int col = 0; col < dimensionY; col++) {
            int currentWeight = matrix[0][col];
            int currentCol = col;
            // Move down the rows
            for (int row = 1; row < dimensionY; row++) {
                // Find the maximum of the three possible moves
                int maxMove = matrix[row][currentCol];
                if (currentCol > 0 && matrix[row][currentCol - 1] > maxMove) {
                    maxMove = matrix[row][currentCol - 1];
                    currentCol--;
                }
                if (currentCol < dimensionX - 1 && matrix[row][currentCol + 1] > maxMove) {
                    maxMove = matrix[row][currentCol + 1];
                    currentCol++;
                }
                currentWeight += maxMove;
            }
            // Update maxWeight if current path is greater
            if (currentWeight > maxWeight) {
                maxWeight = currentWeight;
            }
        }
        printf("Case #%d: %d\n", i + 1, maxWeight);
    }
    return 0;
}