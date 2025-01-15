#include <stdio.h>

void Merge(long long int arr[], long long int left, long long int mid, long long int right) {
    long long int leftSize = mid - left + 1;
    long long int rightSize = right - mid;
    long long int leftArr[leftSize], rightArr[rightSize];
    for (long long int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (long long int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    long long int idx = left;
    long long int leftidx = 0, rightidx = 0;
    while (leftidx < leftSize && rightidx < rightSize) {
        if (leftArr[leftidx] < rightArr[rightidx]) {
            arr[idx] = leftArr[leftidx];
            leftidx++;
            idx++;
        } else {
            arr[idx] = rightArr[rightidx];
            rightidx++;
            idx++;
        }
    }
    while (leftidx < leftSize) {
        arr[idx] = leftArr[leftidx];
        leftidx++;
        idx++;
    }
    while (rightidx < rightSize) {
        arr[idx] = rightArr[rightidx];
        rightidx++;
        idx++;
    }
}

void Divide(long long int arr[], long long int left, long long int right) {
    if (left >= right) {
        return;
    }
    long long int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int binarySearch(long long int arr[], long long int target, long long int left, long long int right) {
    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid + 1;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    long long int size;
    scanf("%lld", &size);
    long long int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    Divide(arr, 0, size - 1);
    long long int query;
    scanf("%lld", &query);
    for (long long int i = 0; i < query; i++) {
        long long int selected;
        scanf("%lld", &selected);
        long long int result = binarySearch(arr, selected, 0, size - 1);
        printf("%lld\n", result);
    }
    return 0;
}

// 5
// 154 172 158 164 160
// 4
// 154
// 172
// 155
// 164