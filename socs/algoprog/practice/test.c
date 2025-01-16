#include<stdio.h>
#include <string.h>

#define LEN 5
#define STR_LEN 20

void bubbleSort(char arr[LEN][STR_LEN]) {
    for(int i = 0; i < LEN; i++) {
        for(int j = 0; j < LEN - 1; j++) {
            int cmp = strcmp(arr[j], arr[j + 1]);
            if(cmp > 0) {
                char tmp[STR_LEN];
                strcpy(tmp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], tmp);
            }
        }
    }
}

int linearSearch(char arr[LEN][STR_LEN], char target[STR_LEN]) {
    for(int i = 0; i < LEN; i++) {
        int cmp = strcmp(arr[i], target);
        if(cmp == 0) {
            return i;
        }
    }
    return -1;
}

void Merge(char arr[LEN][STR_LEN], int left, int mid, int right) {
    int lsize = mid - left + 1;
    int rsize = right - mid;
    char L[lsize][STR_LEN], R[rsize][STR_LEN];
    for(int i = 0; i < lsize; i++) {
        strcpy(L[i], arr[left + i]);
    }
    for(int i = 0; i < rsize; i++) {
        strcpy(R[i], arr[mid + 1 + i]);
    }
    int idx = left;
    int lidx = 0, ridx = 0;
    while(lidx < lsize && ridx < rsize) {
        int cmp = strcmp(L[lidx], R[ridx]);
        if(cmp < 0) {
            strcpy(arr[idx], L[lidx]);
            lidx++;
        } else {
            strcpy(arr[idx], R[ridx]);
            ridx++;
        }
        idx++;
    }
    while(lidx < lsize) {
        strcpy(arr[idx], L[lidx]);
        lidx++;
        idx++;
    }
    while(ridx < rsize) {
        strcpy(arr[idx], R[ridx]);
        ridx++;
        idx++;
    }
}

void Divide(char arr[LEN][STR_LEN], int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int binarySearch(char arr[][STR_LEN], char target[STR_LEN], int left, int right) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);
        if(cmp == 0) {
            return mid;
        }
        if(cmp > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    char str[LEN][STR_LEN] = {
        "donuts",
        "banana",
        "milk",
        "sausage",
        "water",
    };
    // search
    char target[STR_LEN] = "milk";
    bubbleSort(str);
    for(int i = 0; i < LEN; i++) {
        printf("%s ", str[i]);
    }
    printf("\n");
    int lidx = linearSearch(str, target);
    printf("index: %d value: %s\n", lidx, str[lidx]);
    Divide(str, 0, LEN - 1);
    for(int i = 0; i < LEN; i++) {
        printf("%s ", str[i]);
    }
    printf("\n");
    int bidx = binarySearch(str, target, 0, LEN - 1);
    printf("index: %d value: %s\n", bidx, str[bidx]);
    return 0;
}