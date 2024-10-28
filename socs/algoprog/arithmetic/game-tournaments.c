#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long long result = 0;
    for (int i = 1; i <= N; i++) {
        int r = i;
        if (r > N - r) {
            r = N - r;
        }
        long long ans = 1;
        for (int j = 1; j <= r; j++) {
            ans *= N - r + j;
            ans /= j;
        }
        result += ans;
    }
    printf("%lld\n", result);
    return 0;
}
