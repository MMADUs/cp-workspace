#include <stdio.h>

int main() {
    int roll;
    scanf("%d", &roll);
    int position = 0;
    for (int i = 0; i < roll; i++) {
        int number;
        scanf("%d", &number);
        position = (position + number) % 40;
        switch (position) {
            case 30:
                position = 10;
                break;
            case 12:
                position = 28;
                break;
            case 35:
                position = 7;
                break;
        }
    }
    printf("%d\n", position);
    return 0;
}
