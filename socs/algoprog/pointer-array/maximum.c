#include <stdio.h>
#include <limits.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        long long int len;
        scanf("%lld", &len);
        long long int nums[len];
        for (int j = 0; j < len; j++) {
            scanf("%lld", &nums[j]);
        }
        int first = INT_MIN;
        int second = INT_MIN;
        for (int j = 0; j < len; j++) {
            if (nums[j] > first) {
                second = first;
                first = nums[j];
            } else if (nums[j] >= second) {
                second = nums[j];
            }
        }
        const int sum = first + second;
        printf("Case #%d: %d\n", i + 1, sum);
    }
    return 0;
}