#include <stdio.h>

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        long long int shout;
        scanf("%lld", &shout);
        printf("Case #%d:\n", i + 1);
        for (int j = 1; j <= shout; j++) {
            if ((j % 3 == 0 || j % 5 == 0) && j % 15 != 0) {
                printf("%d Jojo\n", j);
            } else {
                printf("%d Lili\n", j);
            }
        }
    }
    return 0;
}
