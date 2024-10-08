#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (long long int i = 0; i < total; i++) {
        int len;
        scanf("%d", &len);
        int nums[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &nums[j]);
        }
        printf("Case #%lld: ", i + 1);
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", nums[i]);
            if (i != 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}