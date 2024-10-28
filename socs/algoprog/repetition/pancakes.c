#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        long long int range;
        scanf("%lld", &range);
        int temp = 1;
        printf("Case %d: ", i + 1);
        for (int j = 0; j < range; j++) {
            temp += j;
            printf("%d", temp);
            if (j != range - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}