#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                               'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                               't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < iter; i++) {
        int index;
        scanf("%d", &index);
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < index; j++) {
            printf("%c", alphabet[j]);
        }
        printf("\n");
    }
    return 0;
}