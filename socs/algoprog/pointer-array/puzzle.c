#include <stdio.h>
#include <stdbool.h>

int main() {
    int size;
    scanf("%d", &size);
    int matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    bool isUnique = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (matrix[i][j] == matrix[i][k]) {
                    isUnique = false;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (matrix[j][i] == matrix[k][i]) {
                    isUnique = false;
                }
            }
        }
    }
    if(isUnique) {
        printf("Yay\n");
    } else {
        printf("Nay\n");
    }
    return 0;
}