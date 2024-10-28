#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        int kinds;
        long long int money;
        scanf("%d %lld", &kinds, &money);
        int price[kinds];
        for (int j = 0; j < kinds; j++) {
            scanf("%d", &price[j]);
        }
        int cheapest = price[0];
        for (int j = 0; j < kinds; j++) {
            if (price[j] < cheapest) {
                cheapest = price[j];
            }
        }
        int buy = money / cheapest;
        printf("Case #%d: %d\n", i + 1, buy);
    }
    return 0;
}