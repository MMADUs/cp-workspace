#include <stdio.h>
#include <string.h>

#define STR_SIZE 201

void MergeChar(char arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    char leftArr[leftSize];
    char rightArr[rightSize];
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
        if(leftArr[leftIdx] < rightArr[rightIdx]) {
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

void DivideChar(char arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    DivideChar(arr, left, mid);
    DivideChar(arr, mid + 1, right);
    MergeChar(arr, left, mid, right);
}

void MergeStr(char arr[][STR_SIZE], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    char leftArr[leftSize][STR_SIZE];
    char rightArr[rightSize][STR_SIZE];
    for(int i = 0; i < leftSize; i++) {
        strcpy(leftArr[i], arr[left + i]);
    }
    for(int i = 0; i < rightSize; i++) {
        strcpy(rightArr[i], arr[mid + i + 1]);
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if(strcmp(leftArr[leftIdx], rightArr[rightIdx]) > 0) {
            strcpy(arr[idx], leftArr[leftIdx]);
            idx++;
            leftIdx++;
        } else {
            strcpy(arr[idx], rightArr[rightIdx]);
            idx++;
            rightIdx++;
        }
    }
    while(leftIdx < leftSize) {
        strcpy(arr[idx], leftArr[leftIdx]);
        idx++;
        leftIdx++;
    }
    while(rightIdx < rightSize) {
        strcpy(arr[idx], rightArr[rightIdx]);
        idx++;
        rightIdx++;
    }
}

void DivideStr(char arr[][STR_SIZE], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    DivideStr(arr, left, mid);
    DivideStr(arr, mid + 1, right);
    MergeStr(arr, left, mid, right);
}

int main() {
    int tc;
    int size;
    scanf("%d %d", &tc, &size);
    char list[tc][STR_SIZE];
    for (int i = 0; i < tc; i++) {
        char letters[size + 1];
        scanf("%s", letters);
        DivideChar(letters, 0, size - 1);
        strcpy(list[i], letters);
    }
    DivideStr(list, 0, tc - 1);
    for (int i = 0; i < tc; i++) {
        printf("%s\n", list[i]);
    }
    return 0;
}

// 3 3
// asj
// efd
// gza