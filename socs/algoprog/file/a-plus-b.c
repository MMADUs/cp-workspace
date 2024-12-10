#include <stdio.h>

int main() {
    FILE *file = fopen("../file/a-plus-b.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int a, b;
    fscanf(file, "%d %d", &a, &b);
    printf("%d\n", a+b);
    return 0;
}