#include <stdio.h>
#include <string.h>

#define SIZE 10

void Merge(long long int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    long long int leftArr[leftSize];
    long long int rightArr[rightSize];
    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + i + 1];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if(leftArr[leftIdx] <= rightArr[rightIdx]) {
            arr[idx] = leftArr[leftIdx];
            idx++;
            leftIdx++;
        } else {
            arr[idx] = rightArr[rightIdx];
            idx++;
            rightIdx++;
        }
    }
    while(leftIdx < leftSize) {
        arr[idx] = leftArr[leftIdx];
        idx++;
        leftIdx++;
    }
    while(rightIdx < rightSize) {
        arr[idx] = rightArr[rightIdx];
        idx++;
        rightIdx++;
    }
}

void Divide(long long int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left+right)/2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    // long long int arr[SIZE] = {5, 17, 6, 20, 14, 16, 0, 24, 9, 11};
    // // 0 5 6 9 11 14 16 17 20 24
    //
    // Divide(arr, 0, SIZE-1);
    // // print hasil
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%lld ", arr[i]);
    // }
    char test1[3];
    strcpy(test1, "hi");
    char test2[3];
    strcpy(test2, "hi");
    int cmp = strcmp(test1, test2);
    printf("%d\n", cmp);
    return 0;
}