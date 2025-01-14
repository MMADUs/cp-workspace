#include <stdio.h>

int jobonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n % 2 != 0) {
        return 1;
    }
    return jobonacci(n - 1) + jobonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    int res = jobonacci(n);
    printf("%d\n", res);
    return 0;
}