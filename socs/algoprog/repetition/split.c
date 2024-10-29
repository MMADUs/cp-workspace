#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int N;
        scanf("%d", &N);
        int arr[N];
        int total_sum = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
            total_sum += arr[j];
        }
        if (total_sum % 2 != 0) {
            printf("Case #%d: No\n", i + 1);
            continue;
        }
        int left_sum = 0;
        int half_sum = total_sum / 2;
        int possible = 0;
        for (int j = 0; j < N; j++) {
            left_sum += arr[j];
            if (left_sum == half_sum) {
                possible = 1;
                break;
            }
        }
        if (possible) {
            printf("Case #%d: Yes\n", i + 1);
        } else {
            printf("Case #%d: No\n", i + 1);
        }
    }
    return 0;
}