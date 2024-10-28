#include <stdio.h>

int fibonacci(int F0, int F1, int K) {
    if (K == 0) {
        return F0;
    } else if (K == 1) {
        return F1;
    } else {
        return fibonacci(F0, F1, K - 1) + fibonacci(F0, F1, K - 2);
    }
}

int main() {
    int F0, F1, K;
    scanf("%d %d", &F0, &F1);
    scanf("%d", &K);
    int result = fibonacci(F0, F1, K);
    printf("%d\n", result);
    return 0;
}
