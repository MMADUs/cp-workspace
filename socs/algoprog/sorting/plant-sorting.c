#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

struct Plant {
    char name[STR_SIZE];
    long long int number;
};

void Merge(struct Plant arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct Plant leftArr[leftSize];
    struct Plant rightArr[rightSize];
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
        if(strcmp(leftArr[leftIdx].name, rightArr[rightIdx].name) <= 0) {
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

void Divide(struct Plant arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    FILE *file = fopen("../sorting/plant-sorting.in", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    int size;
    fscanf(file, "%d", &size);
    struct Plant plant_list[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%lld#%[^\n]", &plant_list[i].number, &plant_list[i].name);
    }
    Divide(plant_list, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%lld %s\n", plant_list[i].number, plant_list[i].name);
    }
    fclose(file);
    return 0;
}