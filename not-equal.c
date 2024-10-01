#include <stdio.h>

int main() {
    long long int lhs1, lhs2, rhs1, rhs2;
    scanf("%lld %lld %lld %lld", &lhs1, &lhs2, &rhs1, &rhs2);
    if (lhs1 * lhs2 > rhs1 + rhs2) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}
