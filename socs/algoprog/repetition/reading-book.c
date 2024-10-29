#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int total, target;
        scanf("%d %d", &total, &target);
        int min;
        if (total == target || target == 1) {
            min = 0;
        } else if (target % 2 == 0) {
            int front = target / 2;
            int back = (total - target) / 2;
            min = (front > back) ? back : front;
        } else {
            int front = (target - 1) / 2;
            int back = (total - target + 1) / 2;
            min = (front > back) ? back : front;
        }
        printf("Case #%d: %d\n", i + 1, min);
    }
    return 0;
}
