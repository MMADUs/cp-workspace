#include <stdio.h>

long long int calculate(long long int n) {
    if (n == 1) {
        return 1;
    }  else if (n % 2 != 0) {
        return calculate(n - 1) + calculate(n + 1);
    } else if (n % 2 == 0) {
        return calculate(n / 2);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        long long int n;
        scanf("%lld", &n);
        long long int result = calculate(n);
        printf("Case #%d: %lld\n", i + 1, result);
    }
    return 0;
}
