#include <stdio.h>

int main(){
    int roll;
    scanf("%d", &roll);
    int position = 0;
    for (int i = 0; i < roll; i++) {
        int num;
        scanf("%d", &num);
        position += num;
        switch (position) {
            case 9:
                position = 21;
            break;
            case 33:
                position = 42;
            break;
            case 53:
                position = 37;
            break;
            case 76:
                position = 92;
            break;
            case 80:
                position = 59;
            break;
            case 97:
                position = 88;
            default:
                // do nothing
            break;
        }
    }
    printf("%d\n", position);
    return 0;
}
