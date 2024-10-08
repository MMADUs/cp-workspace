#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    long long int prices[total];
    for (int i = 0; i < total; i++) {
        scanf("%lld", &prices[i]);
    }
    int changeCount;
    scanf("%d", &changeCount);
    for (int i = 0; i < changeCount; i++) {
        long long int index, newPrice;
        scanf("%lld %lld", &index, &newPrice);
        prices[index - 1] = newPrice;
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < total; j++) {
            printf("%d", prices[j]);
            if (j!=total-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
