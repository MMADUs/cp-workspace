#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        long long int len, weight;
        scanf("%lld %lld", &len, &weight);
        long long int count = 0;
        for (int j = 0; j < len; j++) {
            long long int banana;
            scanf("%lld", &banana);
            if (banana >= weight) {
                count++;
            }
        }
        printf("Case #%d: %lld\n", i + 1, count);
    }
    return 0;
}