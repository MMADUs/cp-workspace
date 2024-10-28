#include <stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);
    for (int t = 1; t <= T; t++) {
        long long int N, X;
        scanf("%lld %lld", &N, &X);
        if (X == N) {
            printf("Case #%d: 0\n", t);
            continue;
        }
        int flips_from_front = X / 2;
        int flips_from_back = (N / 2) - (X / 2);
        if (N % 2 == 1 && X % 2 == 1) {
            flips_from_back += 1;
        }
        int min_flips = flips_from_front < flips_from_back ? flips_from_front : flips_from_back;
        printf("Case #%d: %d\n", t, min_flips);
    }
    return 0;
}
