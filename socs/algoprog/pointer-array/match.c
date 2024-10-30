#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int len;
        scanf("%d", &len);
        int nums[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &nums[j]);
        }
        int bibiIndex, liliIndex;
        scanf("%d %d", &bibiIndex, &liliIndex);
        int bibi = nums[bibiIndex - 1];
        int lili = nums[liliIndex - 1];
        if (bibi == lili) {
            printf("Case #%d : Draw\n", i + 1);
        } else if (bibi > lili) {
            printf("Case #%d : Bibi\n", i + 1);
        } else if (bibi < lili) {
            printf("Case #%d : Lili\n", i + 1);
        }
    }
    return 0;
}