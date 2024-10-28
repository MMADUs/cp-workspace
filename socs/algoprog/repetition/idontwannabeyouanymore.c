#include <stdio.h>

int main(){
    int tc, length;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%d", &length);
        getchar();
        char str[length+10];
        scanf("%[^\n]", str);
        printf("Case #%d: ", i+1);
        for (int j = 0; j < length+1; j++) {
            if (str[j] >= 'a' && str[j] <= 'z') {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
