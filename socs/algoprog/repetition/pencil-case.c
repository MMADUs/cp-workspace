#include <stdio.h>

int main() {
    long long int total;
    scanf("%lld", &total);
    for (int i = 0; i < total; i++) {
        double radius, height;
        scanf("%lf %lf", &radius, &height);
        double pi = 3.14;
        double area = 2 * pi * radius * radius + 2 * pi * radius * height;
        printf("Case #%d: %.2lf\n", i + 1, area);
    }
    return 0;
}