#include <stdio.h>
#include <string.h>

int main(){
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        char str[11 + 1];
        scanf("%s", str);
        printf("Case #%d: ",i+1);
        int count = 0;
        const int length = strlen(str);
        if (str[0] == '.' || str[length-1] == '.') {
            printf("NO\n");
        }
        for (int j = 0; j < length; j++) {
            if (str[i] == '.' ) {
                count++;
                if (str[i+1] == '.') {
                    printf("NO\n");
                }
            }
        }
        if (count == 5) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
