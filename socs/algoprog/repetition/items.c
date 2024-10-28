#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int len;
        scanf("%d", &len);
        long long int total = 0;
        for (int j = 0; j < len; j++) {
            long long int item;
            scanf("%lld", &item);
            total += item;
        }
        printf("Case #%d: %lld\n", i + 1, total);
    }
}