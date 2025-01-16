#include<stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);
    long long int arr[T];
    for(int i = 0; i < T; i++) {
        scanf("%lld", &arr[i]);
    }
    long long int M;
    scanf("%lld", &M);
    long long int target;
    for(int i = 0; i < M; i++) {
        scanf("%lld", &target);
        long long int sum = 0, longest = 0, start = 0;
        for(int j = 0; j < T; j++) {
            sum += arr[j];
            while(sum > target && start <= j) {
                sum -= arr[start++];
            }
            if(sum <= target) {
                long long int current =  j - start + 1;
                if(current > longest) {
                    longest = current;
                }
            }
        }
        if(longest == 0) {
            printf("Case #%d: -1\n", i + 1);
        } else {
            printf("Case #%d: %lld\n", i + 1, longest);
        }
    }
    return 0;
}
