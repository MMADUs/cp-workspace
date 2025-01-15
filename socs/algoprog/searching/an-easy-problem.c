#include <stdio.h>

int main() {
    int len;
    scanf("%d", &len);
    int hard = 0;
    for (int i = 0; i < len; i++) {
        int opinion;
        scanf("%d", &opinion);
        if(opinion == 1) {
            hard = 1;
        }
    }
    if(hard == 1) {
        printf("not easy\n");
    } else {
        printf("easy\n");
    }
    return 0;
}