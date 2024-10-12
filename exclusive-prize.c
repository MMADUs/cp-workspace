#include <stdio.h>

int main(){
    int x, frequency[1000 + 1] = {0};
    scanf("%d", &x);
    int numarr[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &numarr[i]);
        frequency[numarr[i]]++;
    }
    int max = 0;
    for (int i = 0; i < 1000 + 1; i++) {
        if (frequency[i] > max) {
            max = frequency[i];
        }
    }
    printf("%d\n", max);
    return 0;
}