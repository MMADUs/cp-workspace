#include <stdio.h>

int main() {
    for (int i = 1; i <= 4; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b);
    }
    return 0;
}