#include <stdio.h>

int main() {
    long long int total;
    scanf("%lld", &total);
    long long int index[total];
    long long int result[total];
    for (int i = 0; i < total; i++) {
        scanf("%lld", &index[i]);
    }
    for (int i = 0; i < total; i++) {
        long long int value;
        scanf("%lld", &value);
        result[index[i]] = value;
    }
    for (int i = 0; i < total; i++) {
        printf("%lld", result[i]);
        if (i != total - 1) {
            printf(" ");
        }
    }
    return 0;
}
