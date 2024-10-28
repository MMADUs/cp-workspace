#include <stdio.h>

int main() {
    long long T, A, B;
    double rotasi;
    scanf("%lld", &T);
    double hasil[T];
    for (long long i = 0; i < T; i++) {
        scanf("%lld %lld", &A, &B);
        hasil[i] = (double)A * B / 360;
    }
    for (long long i = 0; i < T; i++) {
        printf("%.2lf\n", hasil[i]);
    }
    return 0;
}