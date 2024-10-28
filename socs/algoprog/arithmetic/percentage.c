#include <stdio.h>

int main() {
    int T, P, N;
    double hasil;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &P, &N);
        hasil = (P / 100.0) * N;
        printf("%.2lf\n", hasil);
    }
    return 0;
}