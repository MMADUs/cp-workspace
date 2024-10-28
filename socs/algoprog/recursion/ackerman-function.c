#include <stdio.h>

int calculate(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return calculate(m - 1, 1);
    } else if (m > 0 && n > 0) {
        int temp = calculate(m, n - 1);
        return calculate(m - 1, temp);
    }
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int result = calculate(m, n);
    printf("result: %d\n", result);
    return 0;
}