#include <stdio.h>

int countOnBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        int atLeastThreeOnBits = 0, lessThanThreeOnBits = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int xorValue = arr[i] ^ arr[j];
                int onBits = countOnBits(xorValue);
                if (onBits >= 3) {
                    atLeastThreeOnBits++;
                } else {
                    lessThanThreeOnBits++;
                }
            }
        }
        printf("Case #%d: %d %d\n", t, atLeastThreeOnBits, lessThanThreeOnBits);
    }
    return 0;
}