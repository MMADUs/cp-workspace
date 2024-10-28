#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    int money = 0;
    for (int i = 0; i < total; i++) {
        int each;
        scanf("%d", &each);
        money += each;
    }
    printf("%d\n", money);
    return 0;
}