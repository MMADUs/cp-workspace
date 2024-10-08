#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        long long int b, c;
        scanf("%lld %lld", &b, &c);
        int res = 0;
        for (int j = 1; j <= b; j++) {
            int d;
            scanf("%d", &d);
            if (c > d) {
                res = c;
            }
        }
        printf("Case #%d: %d\n", i, res);
    }
}