#include <stdio.h>

int main() {
    char studentId[11];
    char studentName[101];
    char classChar;
    int classNum;

    scanf("%10s", studentId);
    scanf(" %[^\n]", studentName);
    scanf(" %c %d", &classChar, &classNum);

    printf("Id    : %s\n", studentId);
    printf("Name  : %s\n", studentName);
    printf("Class : %c\n", classChar);
    printf("Num   : %d\n", classNum);

    return 0;
}