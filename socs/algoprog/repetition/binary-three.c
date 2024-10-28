#include <stdio.h>

int main(){
    int tc,x,a,b;
    for (int i = 0; i < tc; i++) {
        scanf("%d",&x);
        int num[x];
        for (int j = 0; j < x; j++) {
            scanf("%d",&num[j]);
            if (num[j] == 0) {
                printf("0");
            }
            if (num[j] == 1) {
                printf("1");
            }
        }
    }
    return 0;
}
