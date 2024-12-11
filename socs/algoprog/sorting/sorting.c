#include <stdio.h>
#include <math.h>

struct metadata {
    long long int difference;
    long long int num_a;
    long long int num_b;
};

void merge(long long int arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    long long int leftArr[leftSize];
    long long int rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if (leftArr[leftIdx] <= rightArr[rightIdx]) {
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

void divide(long long int arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left + right) / 2;
    divide(arr, left, mid);
    divide(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    long long int size;
    scanf("%lld", &size);
    long long int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    // bubble sort
    divide(arr, 0, size - 1);
    // construct as metadata group
    const int size_list = size - 1;
    struct metadata meta_list[size_list];
    for (int i = 0; i < size_list; i++) {
        struct metadata meta;
        meta.difference = abs(arr[i] - arr[i + 1]);
        meta.num_a = arr[i];
        meta.num_b = arr[i + 1];
        meta_list[i] = meta;
    }
    // find maximum difference
    int maximum = 0;
    for (int i = 0; i < size_list; i++) {
        if (maximum < meta_list[i].difference) {
            maximum = meta_list[i].difference;
        }
    }
    // count maximum difference
    int count = 0;
    for (int i = 0; i < size_list; i++) {
        if (maximum == meta_list[i].difference) {
            count++;
        }
    }
    // only displayed maximum difference
    for (int i = 0; i < size_list; i++) {
        if (maximum == meta_list[i].difference) {
            printf("%lld", meta_list[i].num_a);
            printf(" ");
            printf("%lld", meta_list[i].num_b);
            count--;
            if (count) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}