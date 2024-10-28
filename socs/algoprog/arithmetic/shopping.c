#include <stdio.h>

int main() {
    int N;  
    double P; 
    double originalPrice;
    for (int i = 0; i < 4; i++) {
        scanf("%d %lf", &N, &P);
        originalPrice = P / (1 - (N / 100.0));
        printf("$%.2lf\n", originalPrice);
    }
    return 0;
}