#include <stdio.h>
#include <string.h>

void Merge(long long int arr[], int left, int mid, int right) {
    int lsize = mid - left + 1;
    int rsize = right - mid;
    long long int L[lsize], R[rsize];
    for (int i = 0; i < lsize; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < rsize; i++) {
        R[i] = arr[mid + 1 + i];
    }
    int idx = left;
    int lidx = 0, ridx = 0;
    while (lidx < lsize && ridx < rsize) {
        if (L[lidx] <= R[ridx]) {
            arr[idx] = L[lidx];
            lidx++;
        } else {
            arr[idx] = R[ridx];
            ridx++;
        }
        idx++;
    }
    while (lidx < lsize) {
        arr[idx] = L[lidx];
        lidx++;
        idx++;
    }
    while (ridx < rsize) {
        arr[idx] = R[ridx];
        ridx++;
        idx++;
    }
}

void Divide(long long int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    int len;
    scanf("%d", &len);
    long long int dmg[len];
    for (int i = 0; i < len; i++) {
        scanf("%lld", &dmg[i]);
    }
    Divide(dmg, 0, len - 1);
    long long int power;
    scanf("%lld", &power);
    long long int win = 0;
    for (int i = 0; i < len; i++) {
        if(power - dmg[i] < 0) {
            break;
        } else {
            power -= dmg[i];
            win++;
        }
    }
    printf("%lld\n", win);
    return 0;
}

// 5
// 1 2 3 4 5
// 15