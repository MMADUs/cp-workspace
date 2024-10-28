#include <stdio.h>

int main() {
    long long A1, B1, C1, D1;
    long long A2, B2, C2, D2;
    long long A3, B3, C3, D3;

    long long result1, result2, result3;

    scanf(" (%lld+%lld)x(%lld-%lld)", &A1, &B1, &C1, &D1);
    result1 = (A1 + B1) * (C1 - D1);

    scanf(" (%lld+%lld)x(%lld-%lld)", &A2, &B2, &C2, &D2);
    result2 = (A2 + B2) * (C2 - D2);

    scanf(" (%lld+%lld)x(%lld-%lld)", &A3, &B3, &C3, &D3);
    result3 = (A3 + B3) * (C3 - D3);

    printf("%lld %lld %lld\n", result1, result2, result3);
    return 0;
}