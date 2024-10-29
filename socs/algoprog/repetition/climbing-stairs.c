#include <stdio.h>

int main() {
    int len;
    scanf("%d", &len);
    int nums[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < len; i++) {
        if (nums[i] >= nums[i + 1] || i == len - 1) {
            printf("%d", nums[i]);
            if (i != len - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}