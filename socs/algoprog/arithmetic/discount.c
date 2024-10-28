#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    float result = 1.0f - (float)b / a;
    float discount = result * 100;
    printf("%.2f%%\n", discount);
    return 0;
    return 0;
}
