#include <stdio.h>

int multiply(int size, int *matrixA, int *matrixB, int *result) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i * size + j] += matrixA[i * size + k] * matrixB[k * size + j];
            }
        }
    }
    return 0;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int size;
        scanf("%d", &size);
        int firstResult[size][size];
        int finalresult[size][size];
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                firstResult[j][k] = 0;
                finalresult[j][k] = 0;
            }
        }
        int matrixA[size][size];
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                scanf("%d", &matrixA[j][k]);
            }
        }
        int matrixB[size][size];
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                scanf("%d", &matrixB[j][k]);
            }
        }
        multiply(size, matrixA, matrixB, firstResult);
        int matrixC[size][size];
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                scanf("%d", &matrixC[j][k]);
            }
        }
        multiply(size, firstResult, matrixC, finalresult);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                printf("%d", finalresult[j][k]);
                if(k != size - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}