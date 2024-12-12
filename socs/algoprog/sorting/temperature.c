#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define CITY_SIZE 1001

struct City {
    char name[CITY_SIZE];
    // preserve original temperature
    double temperature;
    // temperature metric: 'C' or 'F'
    char metric;
    // the actual celcius for sort
    double celcius;
};

void Merge(struct City arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct City leftArr[leftSize];
    struct City rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + i + 1];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while(leftIdx < leftSize && rightIdx < rightSize) {
        if(leftArr[leftIdx].celcius < rightArr[rightIdx].celcius) {
            arr[idx] = leftArr[leftIdx];
            idx++;
            leftIdx++;
        } else if(leftArr[leftIdx].celcius > rightArr[rightIdx].celcius) {
            arr[idx] = rightArr[rightIdx];
            idx++;
            rightIdx++;
        } else {
            if (strcmp(leftArr[leftIdx].name, rightArr[rightIdx].name) < 0) {
                arr[idx] = leftArr[leftIdx];
                idx++;
                leftIdx++;
            } else {
                arr[idx] = rightArr[rightIdx];
                idx++;
                rightIdx++;
            }
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

void Divide(struct City arr[], const int left, const int right) {
    if(left >= right) {
        return;
    }
    const int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    int count = 0;
    struct City cities[MAX_SIZE];
    while (fscanf(file, "%[^#]#%lf#%c\n", cities[count].name, &cities[count].temperature, &cities[count].metric) != EOF) {
        // convert Fahrenheit to Celcius
        if(cities[count].metric == 'F') {
            const double celcius = (cities[count].temperature - 32) * 5 / 9;
            cities[count].celcius = celcius;
        } else {
            cities[count].celcius = cities[count].temperature;
        }
        count++;
    }
    Divide(cities, 0, count - 1);
    for (int i = 0; i < count; i++) {
        printf("%s is %.2f%c\n", cities[i].name, cities[i].temperature, cities[i].metric);
    }
    fclose(file);
    return 0;
}