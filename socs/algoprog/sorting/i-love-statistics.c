#include <stdio.h>

void Merge(long long int arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    long long int leftArr[leftSize], rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + i + 1];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if (leftArr[leftIdx] < rightArr[rightIdx]) {
            arr[idx] = leftArr[leftIdx];
            idx++;
            leftIdx++;
        } else {
            arr[idx] = rightArr[rightIdx];
            idx++;
            rightIdx++;
        }
    }
    while (leftIdx < leftSize) {
        arr[idx] = leftArr[leftIdx];
        idx++;
        leftIdx++;
    }
    while (rightIdx < rightSize) {
        arr[idx] = rightArr[rightIdx];
        idx++;
        rightIdx++;
    }
}

void Divide(long long int arr[], const int left, const int right) {
    if(left >= right) {
        return;
    }
    const int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int size;
        scanf("%d", &size);
        long long int arr[size];
        for (int j = 0; j < size; j++) {
            scanf("%lld", &arr[j]);
        }
        const int median_index = size / 2;
        Divide(arr, 0, size - 1);
        const double median = arr[median_index];
        long long int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += arr[j];
        }
        const double mean = sum / size;
        printf("Case #%d:\nMean : %.2lf\nMedian : %.2lf\n", i + 1, mean, median);
    }
    return 0;
}

// 2
// 5
// 3 1 2 5 4
// 3
// 1 9 11
