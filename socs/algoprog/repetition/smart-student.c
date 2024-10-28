#include <stdio.h>

int main() {
    int start, jump;
    scanf("%d %d", &start, &jump);
    for (int i = start; i < start + jump; i++) {
        printf("%d\n", i);
    }
    return 0;
}