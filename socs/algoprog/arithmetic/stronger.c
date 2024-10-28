#include <stdio.h>

int main() {
    long long int num;
    scanf("%lld", &num);
    long long int bonus = 0;
    long long int damage = 0;
    for (int i = 0; i < num; i++) {
        damage += 100 + bonus;
        bonus += 50;
    }
    printf("%lld\n", damage);
    return 0;
}