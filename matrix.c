#include <stdio.h>

// Function to sum two 4x4 matrices
void sum(int a[4][4], int b[4][4], int res[4][4]) {
    // loop over rows
    for (int row = 0; row < 4; row++) {
        // loop over columns
        for (int col = 0; col < 4; col++) {
            res[row][col] = a[row][col] + b[row][col];
        }
    }
}

// Function to multiply two 4x4 matrices
void multiple(int a[4][4], int b[4][4], int res[4][4]) {
    // loop over rows
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int result = a[row][col] * b[row][col];
            res[row][col] = result;
        }
    }
}

int main() {
    // matrix a 4x4
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    // matrix b 4x4
    int b[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    // result matrix
    int res[4][4] = {0};

    // Call the sum function
    sum(a, b, res);

    // Print the resulting matrix
    printf("Result matrix:\n");
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", res[row][col]);
        }
        printf("\n");
    }

    return 0;
}
