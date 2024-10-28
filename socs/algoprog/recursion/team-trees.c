#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int len;
        scanf("%d", &len);
        int res = 0;
        for (int i = 0; i < len; i++) {
            int num;
            scanf("%d", &num);
            res += num;
        }
        printf("Case #%d: %d\n", i + 1, res);
    }
    return 0;
}