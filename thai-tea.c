#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int cups;
        int exchange;
        scanf("%d %d", &cups, &exchange);
        int total = cups;
        while (cups >= exchange) {
            cups -= exchange;
            cups += 1;
            total += 1;
        }
        printf("Case #%d: %d\n", i + 1, total);
    }
    return 0;
}