#include <stdio.h>
#include <stdbool.h>

int main() {
    int in, out;
    scanf("%d %d", &in, &out);
    int arr[in];
    for (int i = 0; i < in; i++) {
        scanf("%d", &arr[i]);
    }
    int removed[out];
    for (int i = 0; i < out; i++) {
        scanf("%d", &removed[i]);
    }
    int max = -1;
    for (int i = 0; i < in; i++) {
        bool is_removed = false;
        for (int j = 0; j < out; j++) {
            if (arr[i] == removed[j]) {
                is_removed = true;
                break;
            }
        }
        if (!is_removed && arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum number is %d\n", max);
    return 0;
}

// 1 2 2 2 3 3 4 5 5 5

// 10 3
// 5 3 4 2 5 3 5 1 2 2
// 4 3 5
