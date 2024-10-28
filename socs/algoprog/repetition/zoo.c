#include <stdio.h>

int main() {
    int cages;
    scanf("%d", &cages);
    int total = 0;
    for (int i = 0; i < cages; i++) {
        int animals;
        scanf("%d", &animals);
        total += animals;
    }
    printf("%d\n", total);
}