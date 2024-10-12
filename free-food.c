#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int total;
        int money;
        scanf("%d %d", &total, &money);
        int price[total];
        for (int j = 0; j < total; j++) {
            scanf("%d", &price[j]);
        }
        int bill = 0;
        for (int j = 0; j < total; j++) {
            bill += price[j];
        }
        if (money >= bill) {
            printf("Case #%d: No worries\n", i + 1);
        } else {
            printf("Case #%d: Wash dishes\n", i + 1);
        }
    }
    return 0;
}
