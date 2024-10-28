#include <stdio.h>

int main() {
    int process;
    scanf("%d", &process);
    int output = 1;
    for (int i = 0; i < process; i++) {
        output = output * 2 + 1;
    }
    printf("%d\n", output);
    return 0;
}