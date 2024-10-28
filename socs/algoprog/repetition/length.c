#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        long long int value;
        scanf("%lld", &value);
        int length = 0;
        while (value != 0) {
            value /= 10;
            length++;
        }
        printf("Case #%d: %d\n", i + 1, length);
    }
    return 0;
}