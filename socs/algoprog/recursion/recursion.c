#include <stdio.h>

int calculate(int n, int *count) {
    if(n != 0 && n % 3 == 0) {
        (*count)++;
    }
    if(n == 0) {
        return 1;
    } else if(n == 1) {
        return 2;
    } else if(n % 5 == 0) {
        return n * 2;
    } else {
        return calculate(n - 1, count) + n + calculate(n - 2, count) + n - 2;
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int n;
        scanf("%d", &n);
        int count = 0;
        int result = calculate(n, &count);
        printf("Case #%d: %d %d\n", i + 1, result, count);
    }
    return 0;
}