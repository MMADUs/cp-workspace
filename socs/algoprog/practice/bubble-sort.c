#include <stdio.h>
#include <string.h>

#define SIZE 5

void bubbleSortInt(int angka[SIZE]) {
    // sort
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                const int temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", angka[i]);
    }
}

void bubbleSortString(char sentence[SIZE][50]) {
    // sort
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            int difference = strcmp(sentence[j], sentence[j + 1]);
            if (difference > 0) {
                char temp[50];
                strcpy(temp, sentence[j]);
                strcpy(sentence[j], sentence[j + 1]);
                strcpy(sentence[j + 1], temp);
            }
        }
    }
    // print
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", sentence[i]);
    }
}

int main() {
    int angka[SIZE] = {8, 3, 9, 5, 7};
    char sentence[SIZE][50] = {
        "jeremi", "andrian", "raply", "bangkit", "lintang"
    };
    bubbleSortInt(angka);
    bubbleSortString(sentence);
    return 0;
}