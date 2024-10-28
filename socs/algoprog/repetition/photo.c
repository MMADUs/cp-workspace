#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int height, width;
        scanf("%d %d", &height, &width);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (j == 0 || j == height - 1 || k == 0 || k == width - 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}