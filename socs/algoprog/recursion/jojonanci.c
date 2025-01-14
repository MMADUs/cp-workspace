#include <stdio.h>

int calc(int n, int X, int Y) {
    if (n == 0) {
        return X;
    }
    if (n == 1) {
        return Y;
    }
    return calc(n-1, X, Y) - calc(n-2, X, Y);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        int res = calc(n, x, y);
        printf("Case #%d: %d\n", i + 1, res);
    }
    return 0;
}

// 6
// 0 2 3
// 1 2 3
// 2 2 3
// 3 2 3
// 4 2 3
// 5 0 1
