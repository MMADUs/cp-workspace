#include <stdio.h>

int bubbleSort(int arr[], const int size, const int swap) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                total += swap;
            }
        }
    }
    return total;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int size;
        int swap;
        scanf("%d %d", &size, &swap);
        int arr[size];
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }
        const int result = bubbleSort(arr, size, swap);
        printf("Case #%d: %d\n", i + 1, result);
    }
    return 0;
}