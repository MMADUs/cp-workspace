#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int len;
        scanf("%d", &len);
        int nums[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &nums[j]);
        }
        int odd = 0;
        int even = 0;
        for (int j = 0; j < len; j++) {
            if (nums[j] % 2 != 0) {
                odd++;
            } else {
                even++;
            }
        }
        printf("Odd group : %d integer(s).\n", odd);
        printf("Even group : %d integer(s).\n", even);
        printf("\n");
    }
    return 0;
}