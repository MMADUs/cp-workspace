#include <stdio.h>
#include <stdbool.h>

int main() {
    int total, uniqueCount = 0;
    scanf("%d", &total);
    int rates[total];
    for (int i = 0; i < total; i++) {
        scanf("%d", &rates[i]);
    }
    int unique[total];
    for (int i = 0; i < total; i++) {
        bool isUnique = true;
        for (int j = 0; j < uniqueCount; j++) {
            if (rates[i] == unique[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            unique[uniqueCount] = rates[i];
            uniqueCount++;
        }
    }
    printf("%d\n", uniqueCount);
    return 0;
}
