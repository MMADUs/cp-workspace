#include <stdio.h>

int main() {
    int money, cost;
    scanf("%d %d", &money, &cost);
    int items = 0;
    while (money >= cost) {
        money -= cost;
        items++;
    }
    printf("%d\n", items);
    return 0;
}