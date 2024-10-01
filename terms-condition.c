#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a * b / 100 >= c) {
            printf("Case #%d: %d\n", i, c);
        } else {
            printf("Case #%d: %d\n", i, a * b / 100);
        }
    }
}