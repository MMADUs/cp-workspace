#include <stdio.h>
#include <string.h>

char reverse(char text[], int start, int end) {
    if (start >= end) return 0;
    char temp = text[start];
    text[start] = text[end];
    text[end] = temp;
    reverse(text, start + 1, end - 1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        char text[1000+1];
        char initial[1000+1];
        getchar();
        scanf("%[^\n]", text);
        strcpy(initial, text);
        int len = strlen(text);
        reverse(text, 0, len - 1);
        if (strcmp(text, initial) == 0) {
            printf("Case #%d: yes\n", i + 1);
        } else {
            printf("Case #%d: no\n", i + 1);
        }
    }
    return 0;
}