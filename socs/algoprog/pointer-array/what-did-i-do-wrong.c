#include <stdio.h>
#include <math.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int total;
        scanf("%d", &total);
        int needs[total];
        for (int j = 0; j < total; j++) {
            scanf("%d", &needs[j]);
        }
        int owned[total];
        for (int j = 0; j < total; j++) {
            scanf("%d", &owned[j]);
        }
        int toBuy[total];
        for (int j = 0; j < total; j++) {
            toBuy[j] = needs[j] - owned[j];
        }
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < total; j++) {
            if (toBuy[j] < 0) {
                printf("-");
            }
            printf("%d", abs(toBuy[j]));
            if (j != total - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}