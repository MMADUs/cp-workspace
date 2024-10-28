#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        int need, val;
        scanf("%d %d", &need, &val);
        if (need >= val) {
            printf("Case #%d: Go-Jo\n", i);
        } else {
            printf("Case #%d: Bi-Pay\n", i);
        }
    }
}
