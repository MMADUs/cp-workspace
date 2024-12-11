#include <stdio.h>
#include <string.h>

#define SIZE 10
#define STR_SIZE 50

void MergeInt(long long int arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
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

void DivideInt(long long int arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    DivideInt(arr, left, mid);
    DivideInt(arr, mid + 1, right);
    MergeInt(arr, left, mid, right);
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
        if(leftArr[leftIdx] <= rightArr[rightIdx]) {
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
    long long int arr[SIZE] = {5, 17, 6, 20, 14, 16, 0, 24, 9, 11};
    DivideInt(arr, 0, SIZE-1);
    // print hasil
    for (int i = 0; i < SIZE; i++) {
        printf("%lld ", arr[i]);
    }

    char sentence[SIZE][50] = {
        "banana",
        "apple",
        "cherry",
        "date",
        "elderberry",
        "fig",
        "grape",
        "honeydew",
        "kiwi",
        "lemon"
    };
    DivideInt(sentence, 0, SIZE-1);
    // print hasil
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", sentence[i]);
    }
    return 0;
}