#include <stdio.h>

void Merge(int num[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int leftArr[leftSize], rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = num[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = num[mid + 1 + i];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if (leftArr[leftIdx] < rightArr[rightIdx]) {
            num[idx] = leftArr[leftIdx];
            leftIdx++;
            idx++;
        } else {
            num[idx] = rightArr[rightIdx];
            rightIdx++;
            idx++;
        }
    }
    while (leftIdx < leftSize) {
        num[idx] = leftArr[leftIdx];
        leftIdx++;
        idx++;
    }
    while (rightIdx < rightSize) {
        num[idx] = rightArr[rightIdx];
        rightIdx++;
        idx++;
    }
}

void Divide(int num[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    Divide(num, left, mid);
    Divide(num, mid + 1, right);
    Merge(num, left, mid, right);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++) {
        int len;
        scanf("%d", &len);
        int arr[len];
        for(int j = 0; j < len; j++) {
            scanf("%d", &arr[j]);
        }
        // 1 6 9 7 2 3
        Divide(arr, 0, len - 1);
        // 1 2 3 6 7 9
        int halfSize = len / 2;
        // 1 2 3
        // 6 7 9
        int upmax = 0;
        for(int j = 0; j < halfSize - 1; j++) {
            int diff = arr[j + 1] - arr[j];
            if (diff > upmax) {
                upmax = diff;
            }
        }
        int downmax = 0;
        for(int j = halfSize; j < len - 1; j++) {
            int diff = arr[j + 1] - arr[j];
            if (diff > downmax) {
                downmax = diff;
            }
        }
        if (upmax > downmax) {
            printf("Case #%d: %d\n", i + 1, upmax);
        } else {
            printf("Case #%d: %d\n", i + 1, downmax);
        }
    }
    return 0;
}

// 2
// 6
// 1 6 9 7 2 3
// 4
// 1 1 2 2