#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        int size;
        scanf("%d", &size);
        long long int nums[size][size];
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                scanf("%lld", &nums[j][k]);
            }
        }
        printf("Case #%d: ", i + 1);
        for (int x = 0; x < size; x++) {
            int res = 0;
            for (int y = 0; y < size; y++) {
                res += nums[y][x];
            }
            printf("%d", res);
            if (x != size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
