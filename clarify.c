#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    int clarified = 0;
    for (int i = 0; i < iter; i++) {
        int sent, solved, viewed;
        scanf("%d %d %d", &sent, &solved, &viewed);
        if (solved > viewed) {
            clarified++;
        }
    }
    printf("%d\n", clarified);
    return 0;
}