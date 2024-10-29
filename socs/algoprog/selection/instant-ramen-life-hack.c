#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        int need, av1, av2;
        scanf("%d %d %d", &need, &av1, &av2);
        if (av1 + av2 >= need) {
            printf("Case #%d: yes\n", i);
        } else {
            printf("Case #%d: no\n", i);
        }
    }
}
