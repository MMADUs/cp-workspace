#include <stdio.h>

int main(){
    int pyshical, magical, pure;
    scanf("%d", &pyshical);
    scanf("%d", &magical);
    scanf("%d", &pure);

    float totaldamage = 0.2 * pyshical + 0.3 * magical + 0.5 * pure;
    printf("%.2f\n", totaldamage);
    return 0;
}