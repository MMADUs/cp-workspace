#include <stdio.h>

int fibbonaci(int n, int *count) {
    (*count)++;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibbonaci(n - 1, count) + fibbonaci(n - 2, count);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int n;
        int count = 0;
        scanf("%d", &n);
        fibbonaci(n, &count);
        printf("Case #%d: %d\n", i + 1, count);
    }
    return 0;
}
