#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        int frog1, frog2;
        scanf("%d %d", &frog1, &frog2);
        if (frog1 % 2 == 0 || frog2 % 2 == 0) {
            printf("Case #%d: Party time!\n", i);
        } else {
            printf("Case #%d: Need more frogs\n", i);
        }
    }
}
