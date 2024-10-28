#include <stdio.h>

int main() {
    double L, B, H;
    double luas_segitiga, luas_permukaan;
    scanf("%lf %lf %lf", &L, &B, &H);
    luas_segitiga = 0.5 * B * H;
    luas_permukaan = 2 * luas_segitiga + 3 * L * B;
    printf("%.3lf\n", luas_permukaan);
    return 0;
}