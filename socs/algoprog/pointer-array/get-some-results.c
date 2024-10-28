#include <stdio.h>

#define MAX_DIM 100

void multiplyMatrix(int A[][MAX_DIM], int B[][MAX_DIM], int C[][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void copyMatrix(int src[][MAX_DIM], int dest[][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int total, dimension;
    int A[MAX_DIM][MAX_DIM], B[MAX_DIM][MAX_DIM], C[MAX_DIM][MAX_DIM], temp[MAX_DIM][MAX_DIM];

    scanf("%d", &total);

    for (int i = 0; i < total; i++) {
        scanf("%d", &dimension);

        // Read first matrix (A)
        for (int k = 0; k < dimension; k++) {
            for (int l = 0; l < dimension; l++) {
                scanf("%d", &A[k][l]);
            }
        }

        // Read second matrix (B) and multiply with A
        for (int k = 0; k < dimension; k++) {
            for (int l = 0; l < dimension; l++) {
                scanf("%d", &B[k][l]);
            }
        }
        multiplyMatrix(A, B, C, dimension);

        // Read third matrix (temp) and multiply with previous result
        for (int k = 0; k < dimension; k++) {
            for (int l = 0; l < dimension; l++) {
                scanf("%d", &temp[k][l]);
            }
        }
        multiplyMatrix(C, temp, A, dimension);  // Reuse A to store final result

        // Print the result
        printf("Case #%d:\n", i + 1);
        printMatrix(A, dimension);
    }

    return 0;
}