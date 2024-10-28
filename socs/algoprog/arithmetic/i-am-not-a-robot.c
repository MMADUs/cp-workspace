#include <stdio.h>

int main(){
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    long double result = (float)b / a * 100;
    printf("%.4Lf%%", result);
    return 0;
}