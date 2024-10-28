#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a > b || b < c || a > c) {
        printf("-1\n");
    }
    else if (c - a == b - c) {
        printf("%d\n", c - a);
    } else {
        printf("-1\n");
    }

    return 0;
}
