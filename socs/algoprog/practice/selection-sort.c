#include <stdio.h>
#include <string.h>

#define SIZE 5

void selectionSortInt(int angka[SIZE]) {
    // sort
    for (int i = 0; i < SIZE; i++) {
        int index = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (angka[j] < angka[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = angka[i];
            angka[i] = angka[index];
            angka[index] = temp;
        }
    }
    // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", angka[i]);
    }
}

void selectionSortString(char sentence[SIZE][50]) {
    // sort
    for (int i = 0; i < SIZE; i++) {
        int index = i;
        for (int j = i + 1; j < SIZE; j++) {
            int difference = strcmp(sentence[j], sentence[index]);
            if (difference < 0) {
                index = j;
            }
        }
        if (index != i) {
            char temp[50];
            strcpy(temp, sentence[i]);
            strcpy(sentence[i], sentence[index]);
            strcpy(sentence[index], temp);
        }
    }
    // print
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", sentence[i]);
    }
}

int main() {
    int angka[SIZE] = {5, 7, 3, 6, 9};
    char sentence[SIZE][50] = {
        "jeremi", "andrian", "raply", "bangkit", "lintang"
    };
    selectionSortInt(angka);
    selectionSortString(sentence);
    return 0;
}