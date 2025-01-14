#include <stdio.h>

void calc(int input, int expect) {
    if (expect == input) {
        printf("YES");
        return;
    }
    if (input == 1) {
        printf("NO");
        return;
    }
    if (input % 2 == 0) {
        calc(input / 2, expect);
    } else {
        calc(input * 3 + 1, expect);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int input;
        int expect;
        scanf("%d %d", &input, &expect);
        printf("Case #%d: ", i + 1);
        calc(input, expect);
        printf("\n");
    }
    return 0;
}

// 3
// 2 1
// 5 6
// 12 5