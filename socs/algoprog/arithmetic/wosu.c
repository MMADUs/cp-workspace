#include <stdio.h>

int main() {
    long long int num;
    scanf("%lld", &num);
    long long int bonus = 0;
    long long int total = 0;
    for (int i = 0; i < num; i++) {
        total += 100 + bonus;
        bonus += 50;
    }
    printf("%lld\n", total);
    return 0;
}