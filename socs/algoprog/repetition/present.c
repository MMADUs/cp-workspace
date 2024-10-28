#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int len;
        scanf("%d", &len);
        int scores[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &scores[j]);
        }
        int highest = 0;
        for (int j = 0; j < len; j++) {
            if (scores[j] > highest) {
                highest = scores[j];
            }
        }
        int students = 0;
        for (int j = 0; j < len; j++) {
            if (scores[j] == highest) {
                students++;
            }
        }
        printf("Case #%d: %d\n", i + 1, students);
    }
    return 0;
}
