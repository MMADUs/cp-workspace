#include <stdio.h>

int main() {
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    int mid1 = (num1 / 10) % 10;
    int mid2 = (num2 / 10) % 10;
    int mid3 = (num3 / 10) % 10;
    printf("%d\n%d\n%d\n", mid1, mid2, mid3);
    return 0;
}