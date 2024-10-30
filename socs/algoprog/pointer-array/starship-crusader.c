#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        long long int total;
        scanf("%lld", &total);
        long long int result[total];
        for (int j = 0; j < total; j++) {
            scanf("%lld", &result[j]);
        }
        long long int requirement[total];
        for (int j = 0; j < total; j++) {
            scanf("%lld", &requirement[j]);
        }
        int failCount = 0;
        for (int j = 0; j < total; j++) {
            if (result[j] < requirement[j]) {
                failCount++;
            }
        }
        printf("Case #%d: %d\n", i + 1, failCount);
    }
    return 0;
}