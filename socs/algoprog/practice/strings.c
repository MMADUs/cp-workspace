#include <stdio.h>
#include <string.h>

int main() {
    // insert
    char str[100];
    scanf("%s", str);
    printf("%s\n", str);
    // flexible string
    char str1[100];
    getchar();
    scanf("%[^\n]", str1);
    printf("%s\n", str1);
    // length
    int len = strlen(str1);
    printf("%d\n", len);
    // loop
    for (int i = 0; i < len; i++) {
        if (str1[i] == 'A') {
            printf("%c\n", str1[i]);
        }
    }
}