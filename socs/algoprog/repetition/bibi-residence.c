#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        long long int N;
        scanf("%lld", &N);
        long long int heights[N];
        for (int i = 0; i < N; i++) {
            scanf("%lld", &heights[i]);
        }
        int min_diff = abs(heights[1] - heights[0]);
        for (int i = 1; i < N; i++) {
            int diff = abs(heights[i] - heights[i - 1]);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        printf("Case #%d: %d\n", t, min_diff);
    }
    return 0;
}
