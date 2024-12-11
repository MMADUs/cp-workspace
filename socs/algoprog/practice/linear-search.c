#include <stdio.h>
#define SIZE 9

int linearSearch(int angka[SIZE], int angkaDicari) {
    for (int i = 0; i < SIZE; i++) {
        if(angka[i] == angkaDicari) {
            return i;
        }
    }
    return -1;
}

int main() {
    int angka[SIZE] = {5, 2, 4, 3, 6, 8, 9, 7, 10};
    int lookup;
    scanf("%d", &lookup);
    int index = linearSearch(angka, lookup);
    printf("%d\n", index);
    return 0;
}