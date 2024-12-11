#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], const int target, int left, int right) {
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    qsort(arr, size, sizeof(int), compare_int);
    const int result = binarySearch(arr, target, 0, size - 1);
    printf("%d\n", result);
    return 0;
}