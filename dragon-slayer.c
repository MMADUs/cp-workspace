#include <stdio.h>

int main() {
    long long int weapon, dragon;
    scanf("%lld %lld", &weapon, &dragon);
    long long int w[weapon];
    long long int d[dragon];
    for(int i = 0; i < weapon; i++) {
        scanf("%lld", &w[i]);
    }
    for(int i = 0; i < dragon; i++) {
        scanf("%lld", &d[i]);
    }
    int bigw = 0;
    int bigd = 0;
    for(int i = 0; i < weapon; i ++) {
        if (w[i] > bigw) {
            bigw = w[i];
        }
    }
    for(int i = 0; i < dragon; i ++) {
        if (d[i] > bigd) {
            bigd = d[i];
        }
    }
    if (bigw > bigd) {
        printf("The dark secret was true\n");
    } else {
        printf("Secret debunked\n");
    }
    return 0;
}