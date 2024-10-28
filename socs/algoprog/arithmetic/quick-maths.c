#include <stdio.h>

int main() {
    long long int num;
    scanf("%lld", &num);
    printf("%lld plus %lld is %lld\n", num, num, num + num);
    printf("minus one is %lld\n", num + num - 1);
    return 0;
}