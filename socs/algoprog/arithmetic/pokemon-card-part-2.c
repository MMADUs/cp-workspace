#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    double percent = (double)X / Y * 100;
    printf("%.2lf%\n", percent);
    return 0;
}