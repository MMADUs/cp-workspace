#include <stdio.h>

int main(){
    int len, frequency[1000+1] = {0};
    scanf("%d", &len);
    int nums[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
        frequency[nums[i]]++;
    }
    int max = 0;
    for (int i = 0; i < 1000 + 1; i++) {
        if (frequency[i] > max) {
            max = frequency[i];
        }
    }
    printf("%d\n", max);
    return 0;
}