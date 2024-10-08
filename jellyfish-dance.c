#include  <stdio.h>

int main() {
    int days;
    scanf("%d", &days);
    int views[days];
    for (int i = 0; i < days; i++) {
        scanf("%d", &views[i]);
    }
    int checks;
    scanf("%d", &checks);
    for (int i = 0; i < checks; i++) {
        int first, last, res = 0;
        scanf("%d %d", &first, &last);
        for (int j = first - 1; j <= last - 1; j++) {
            res += views[j];
        }
        printf("Case #%d: %d\n", i + 1, res);
    }
    return 0;
}