#include <stdio.h>

#define STR_SIZE 50

struct Student {
    int number;
    char name[STR_SIZE];
};

void Merge(struct Student arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct Student leftArr[leftSize];
    struct Student rightArr[rightSize];
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
        if(leftArr[leftIdx].number < rightArr[rightIdx].number) {
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

void Divide(struct Student arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int size;
    fscanf(file, "%d", &size);
    struct Student students[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%10d %[^\n]", &students[i].number, students[i].name);
    }
    Divide(students, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", students[i].number, students[i].name);
    }
    fclose(file);
    return 0;
}