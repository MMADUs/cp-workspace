#include <stdio.h>

#define STR_SIZE 101

struct Assignment {
    char subject[STR_SIZE];
    long long int deadline;
};

void Merge(struct Assignment arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct Assignment leftArr[leftSize];
    struct Assignment rightArr[rightSize];
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
        if (leftArr[leftIdx].deadline <= rightArr[rightIdx].deadline) {
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

void Divide(struct Assignment arr[], const int left, const int right) {
    if(left >= right) {
        return;
    }
    const int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

// void bubbleSort(struct Assignment assignment[], const int size) {
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size - 1; j++) {
//             if (assignment[j].deadline > assignment[j + 1].deadline) {
//                 const struct Assignment temp = assignment[j];
//                 assignment[j] = assignment[j + 1];
//                 assignment[j + 1] = temp;
//             }
//         }
//     }
// }

int main() {
    int size;
    scanf("%d", &size);
    struct Assignment assignments[size];
    for (int i = 0; i < size; i++) {
        scanf("%s %lld", &assignments[i].subject, &assignments[i].deadline);
    }
    Divide(assignments, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%s\n", assignments[i].subject);
    }
    return 0;
}