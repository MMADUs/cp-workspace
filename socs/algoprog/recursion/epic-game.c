#include <stdio.h>

long long int calculate(long long int n, int *counter) {
    (*counter)++;
    if (n <= 1 && *counter % 2 == 0) {
        return printf("Jojo");
    } else if (n <= 1 && *counter % 2 != 0) {
        return printf("Lili");
    } else if (n % 2 == 0) {
        return calculate(n / 2, counter);
    } else if (n % 2 != 0) {
        return calculate(n * 3 + 1, counter);
    }
}

int main() {
    long long int tc;
    scanf("%lld", &tc);
    for (int i = 0; i < tc; i++) {
        long long int n;
        int counter = 0;
        scanf("%lld", &n);
        printf("Case #%d: ", i + 1);
        calculate(n, &counter);
        printf("\n");
    }
    return 0;
}