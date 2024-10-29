#include <stdio.h>
#include <string.h>

int isValidIPv10(char *ip) {
    int dotCount = 0;
    int numCount = 0;
    int length = strlen(ip);
    for (int i = 0; i < length; i++) {
        if (ip[i] == '.') {
            if (numCount == 0) {
                return 0;
            }
            dotCount++;
            numCount = 0;
        } else if (ip[i] >= '0' && ip[i] <= '9') {
            numCount++;
        } else {
            return 0;
        }
    }
    if (numCount == 0) {
        return 0;
    }
    return (dotCount == 5);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char ip[100+1];
        scanf("%s", ip);
        if (isValidIPv10(ip)) {
            printf("Case #%d: YES\n", t);
        } else {
            printf("Case #%d: NO\n", t);
        }
    }
    return 0;
}