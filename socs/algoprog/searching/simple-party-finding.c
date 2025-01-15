#include <stdio.h>

void Merge(int arr[], int left, int mid, int right) {
    int lsize = mid - left + 1;
    int rsize = right - mid;
    int ltemp[lsize], rtemp[rsize];
    for (int i = 0; i < lsize; i++) {
        ltemp[i] = arr[left + i];
    }
    for (int i = 0; i < rsize; i++) {
        rtemp[i] = arr[mid + 1 + i];
    }
    int idx = left;
    int lidx = 0, ridx = 0;
    while (lidx < lsize && ridx < rsize) {
        if (ltemp[lidx] < rtemp[ridx]) {
            arr[idx] = ltemp[lidx];
            lidx++;
            idx++;
        } else {
            arr[idx] = rtemp[ridx];
            ridx++;
            idx++;
        }
    }
    while (lidx < lsize) {
        arr[idx] = ltemp[lidx];
        lidx++;
        idx++;
    }
    while (ridx < rsize) {
        arr[idx] = rtemp[ridx];
        ridx++;
        idx++;
    }
}

void Divide(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1 , right);
    Merge(arr, left, mid, right);
}

int binarySearch(int arr[], int target, int left, int right) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int len;
        scanf("%d", &len);
        int arr[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &arr[j]);
        }
        Divide(arr, 0, len - 1);
        int query;
        scanf("%d", &query);
        int idx = binarySearch(arr, query, 0, len - 1);
        if (idx == -1) {
            printf("CASE #%d: -1 -1\n", i + 1);
        } else if (idx == 0) {
            printf("CASE #%d: %d %d\n", i + 1, arr[idx], arr[idx + 1]);
        } else if(idx == len - 1) {
            printf("CASE #%d: %d %d\n", i + 1, arr[idx - 1], arr[idx]);
        } else {
            printf("CASE #%d: %d %d\n", i + 1, arr[idx], arr[idx + 1]);
        }
    }
    return 0;
}

// 3
// 10
// 3246 4255 4873 5004 5095 6001 6692 7100 7610 9712
// 9712
// 8
// 4957 5444 5464 5634 6149 6622 8313 9492
// 4957
// 6
// 5393 6021 7233 8115 8118 9304
// 9999

// 3

// 4
// 1 2 3 4
// 1

// 4
// 1 2 3 4
// 2

// 4
// 1 2 3 4
// 4

// 4
// 1 2 3 4
// 5