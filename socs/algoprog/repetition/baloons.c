#include <stdio.h>

int main() {
    long long int iter, strength;
    scanf("%lld %lld", &iter, &strength);
    long long int baloons[iter];
    for (int i = 0; i < iter; i++) {
        scanf("%lld", &baloons[i]);
    }
    int popped = 0;
    for (int i = 0; i < iter; i++) {
        if (strength > baloons[i]) {
            popped++;
        }
    }
    printf("%d\n", popped);
    return 0;
}
    
