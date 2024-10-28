#include <stdio.h>

int main() {
    int dim_x, dim_y;
    scanf("%d %d", &dim_x, &dim_y);
    int matrix[dim_x][dim_y];
    for (int i = 0; i < dim_x; i++) {
        for (int j = 0; j < dim_y; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int changes;
    scanf("%d", &changes);
    for (int i = 0; i < changes; i++) {
        int index_x, index_y;
        int new_val;
        scanf("%d %d %d", &index_x, &index_y, &new_val);
        matrix[index_x - 1][index_y - 1] = new_val;
    }
    for (int i = 0; i < dim_x; i++) {
        for (int j = 0; j < dim_y; j++) {
            printf("%d ", matrix[i][j]);
            if(j < dim_y - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}