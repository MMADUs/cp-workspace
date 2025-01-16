#include <stdio.h>

long long int calc(long long int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

long long int binarySearch(long long int target) {
    long long int res = 0, left = 1, right = 3250000;
    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (calc(mid) >= target) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        long long int num;
        scanf("%lld", &num);
        long long int res = binarySearch(num);
        printf("Case #%d: %lld\n", i + 1, res);
    }
    return 0;
}
