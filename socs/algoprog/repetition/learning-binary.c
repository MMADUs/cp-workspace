#include <stdio.h>

int main() {
    int T;
    int X, P;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &X, &P);
        int bit_value = (X >> P) & 1;
        printf("%d\n", bit_value);
    }
    return 0;
}