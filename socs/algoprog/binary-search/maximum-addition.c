#include<stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);
    for(int i = 0;i < T; i++) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        long long int arr[a];
        for(int j = 0;j < a;j++) {
            scanf("%lld", &arr[j]);
        }
        long long int sum = 0, start = 0, longest = 0;
        for(int j = 0; j < a; j++) {
            sum += arr[j];
            while(sum > b) {
                sum -= arr[start++];
            }
            if(sum <= b) {
                long long int current = j - start + 1;
                if(current > longest) {
                    longest = current;
                }
            }
        }
        if(longest == 0) {
            printf("Case #%d: -1\n",i+1);
        } else {
            printf("Case #%d: %lld\n",i+1, longest);
        }
    }
    return 0;
}
