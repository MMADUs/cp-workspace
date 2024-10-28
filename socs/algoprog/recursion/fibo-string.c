#include <stdio.h>

int fibonacci(int num, char a, char b) {
    if (num == 0) {
        return printf("%c", a);
    } else if (num == 1) {
        return printf("%c", b);
    } else {
        fibonacci(num - 1, a, b);
        fibonacci(num - 2, a, b);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int num;
        char a, b;
        scanf("%d %c %c", &num, &a, &b);
        printf("Case #%d: ", i + 1);
        fibonacci(num, a, b);
        printf("\n");
    }

    return 0;
 }
