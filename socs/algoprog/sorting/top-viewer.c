#include <stdio.h>

#define SIZE 5
#define STR_SIZE 1001

struct Video {
    char title[STR_SIZE];
    char artist[STR_SIZE];
    int view;
};

void Merge(struct Video arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct Video leftArr[leftSize];
    struct Video rightArr[rightSize];
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
        if(leftArr[leftIdx].view > rightArr[rightIdx].view) {
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

void Divide(struct Video arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    FILE *file = fopen("../sorting/top-viewer.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    struct Video videos[SIZE];
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%[^#]#%[^#]#%d", videos[i].title, videos[i].artist, &videos[i].view);
    }
    Divide(videos, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        printf("%s by %s - %d\n", videos[i].title, videos[i].artist, videos[i].view);
    }
    fclose(file);
    return 0;
}