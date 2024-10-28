#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int total;
        scanf("%d", &total);
        char match[total + 1];
        scanf("%s", &match);
        int bibi = 0;
        int lili = 0;
        for (int j = 0; j < total; j++) {
            if(match[j] == 'B') {
                bibi++;
            } else if(match[j] == 'L') {
                lili++;
            }
        }
        if (bibi == lili) {
            printf("None\n");
        } else if(bibi > lili) {
            printf("Bibi\n");
        } else if(bibi < lili) {
            printf("Lili\n");
        }
    }
    return 0;
}