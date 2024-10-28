#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int plates;
        int capacity;
        int initial;
        scanf("%d %d %d", &plates, &capacity, &initial);
        int portions[plates];
        for (int j = 0; j < plates; j++) {
            scanf("%d", &portions[i]);
        }
        int result = initial;
        if (result > capacity) {
            result = 0;
        }
        for (int j = 0; j < plates; j++) {
            if (portions[j] > result && portions[j] < capacity) {
                result = portions[j];
            }
        }
        printf("Case #%d: %d\n", i + 1, result);
    }
    return 0;
}