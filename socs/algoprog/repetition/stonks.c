#include <stdio.h>

int main() {
    long long int len;
    scanf("%lld", &len);
    long long int earnings[len];
    for (int i = 0; i < len; i++) {
        scanf("%lld", &earnings[i]);
    }
    long long int profits = 0;
    for (int i = 0; i < len; i++) {
        if (earnings[i] > 0) {
            profits += earnings[i];
        }
    }
    printf("%lld\n", profits);
    return 0;
}
