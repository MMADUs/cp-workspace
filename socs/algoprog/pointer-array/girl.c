#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        char str[100000+1];
        scanf("%s", str);
        int len = strlen(str);
        char unique[100000+1];
        int uniqueCount = 0;
        for (int i = 0; i < len; i++) {
            bool isUnique = true;
            for (int j = 0; j < uniqueCount; j++) {
                if (str[i] == unique[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                unique[uniqueCount] = str[i];
                uniqueCount++;
            }
        }
        if (uniqueCount % 2 != 0) {
            printf("Case #%d: Ewwww\n", i + 1);
        } else {
            printf("Case #%d: Yay\n", i + 1);
        }
    }
    return 0;
}
