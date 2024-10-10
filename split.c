#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        long long int len;
        scanf("%lld", &len);
        int nums[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &nums[j]);
        }
        const int split = len / 2;
        int left = 0;
        int right = 0;
        for (int j = 0; j < split; j++) {
            left += nums[j];
        }
        for (int j = split; j < len; j++) {
            right += nums[j];
        }
        if (left == right) {
            printf("Case #%d: Yes\n", i + 1);
        } else {
            printf("Case #%d: No\n", i + 1);
        }
    }
    return 0;
}