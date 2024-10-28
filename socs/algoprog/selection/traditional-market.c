#include <stdio.h>

int main() {
    long long int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if (a > b && a > c) {
        if (b > c) {
            printf("Daging\n");
            printf("Sayur\n");
            printf("Sayur\n");
        } else {
            printf("Daging\n");
            printf("Telur\n");
            printf("Sayur\n");
        }
    } else if (b > c && b > a) {
        if (a > c) {
            printf("Sayur\n");
            printf("Daging\n");
            printf("Telur\n");
        } else {
            printf("Sayur\n");
            printf("Telur\n");
            printf("Daging\n");
        }
    } else {
        if (a > b) {
            printf("Telur\n");
            printf("Daging\n");
            printf("Sayur\n");
        } else {
            printf("Telur\n");
            printf("Sayur\n");
            printf("Daging\n");
        }
    }
}
