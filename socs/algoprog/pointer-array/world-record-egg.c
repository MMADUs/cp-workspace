#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int day;
        scanf("%d", &day);
        long long int previous = 0;
        long long int next = 0;
        for (int j = 0; j < day; j++) {
            if (j == 0) {
                continue;
            } else if (j == 1) {
                next++;
            } else {
                long long int temp = next;
                next = previous + next;
                previous = temp;
            }
        }
        printf("Case #%d: %lld\n", i + 1, next);
    }
    return 0;
}