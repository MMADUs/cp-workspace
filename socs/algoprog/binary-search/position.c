#include <stdio.h>

void Merge(long long int arr[], long long int left, long long int mid, long long int right) {
    long long int lsize = mid - left + 1;
    long long int rsize = right - mid;
    for (long long int i = 0; i < lsize; i++) {
        arr[i] = arr[left + i];
    }
    for (long long int i = 0; i < rsize; i++) {
        arr[left + i] = arr[mid + 1 + i];
    }
    long long int idx = left;
    long long int lidx = 0, ridx = 0;
    while (lidx < lsize && ridx < rsize) {
        if (arr[lidx] < arr[ridx]) {
            arr[idx] = arr[lidx];
            lidx++;
        } else {
            arr[idx] = arr[ridx];
            ridx++;
        }
        idx++;
    }
    while (lidx < lsize) {
        arr[idx] = arr[lidx];
        lidx++;
        idx++;
    }
    while (ridx < rsize) {
        arr[idx] = arr[ridx];
        ridx++;
        idx++;
    }
}

void Divide(long long int arr[], long long int right, long long int left) {
    if (left >= right) {
        return;
    }
    long long int mid = (right + left) / 2;
    Divide(arr, left, right);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

long long int binarySearch(long long int arr[], long long int target, long long int left, long long int right) {
    long long int res = -1;
    while(left <= right) {
        long long int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            res = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res == -1 ? -1 : res + 1;
}

int main() {
    long long int len, qlen;
    scanf("%lld %lld", &len, &qlen);
    long long int arr[len];
    for (int i = 0; i < len; i++) {
        scanf("%lld", &arr[i]);
    }
    Divide(arr, 0, len - 1);
    long long int query[qlen];
    for (int i = 0; i < qlen; i++) {
        scanf("%lld", &query[i]);
    }
    for (int i = 0; i < qlen; i++) {
        long long int idx = binarySearch(arr, query[i], 0, len - 1);
        if(idx == -1) {
            printf("-1\n");
        } else {
            printf("%lld\n", idx);
        }
    }
    return 0;
}

// 3 2
// 1 2 3
// 1 2

// 1
// 2

// 4 2
// 1 3 5 5
// 100 5

// -1
// 3