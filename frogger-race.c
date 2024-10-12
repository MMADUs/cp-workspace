#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        long long int finish;
        scanf("%lld", &finish);
        int position = 0;
        int jump = 0;
        for (int j = 0; position < finish; j++) {
            position += j + 1;
            jump++;
        }
        printf("Case #%d: %d\n", i + 1, jump);
    }
    return 0;
}