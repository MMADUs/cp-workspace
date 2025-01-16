#include<stdio.h>

int search(long long int arr[], long long int target, long long int left, long long int right) {
    int baseIdx = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= target) {
            left = mid + 1;
            baseIdx = mid;
        } else {
            right = mid - 1;
        }
    }
    return baseIdx;
}

int main() {
    int T;
    scanf("%d", &T);
    long long int arr[T], prev = 0;
    for(int i = 0; i < T; i++) {
        int temp;
        scanf("%lld", &temp);
        arr[i] = temp + prev;
        prev = arr[i];
    }
    long long int M;
    scanf("%lld", &M);
    for(int i = 0; i < M; i++) {
        long long int target;
        scanf("%lld", &target);
        long long int idx = search(arr, 0, T-1, target);
        if(idx == -1) {
            printf("Case #%d: -1\n", i+1);
        } else {
            printf("Case #%d: %lld\n", i+1, idx + 1);
        }
    }
    return 0;
}
