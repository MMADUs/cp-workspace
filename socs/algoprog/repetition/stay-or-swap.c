#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int largest_portion = K;
        for (int j = 0; j < N; j++){
            int portion;
            scanf("%d", &portion);
            if (portion <= M && portion > largest_portion){
                largest_portion = portion;
            }
        }
        printf("Case #%d: %d\n", i, largest_portion);
    }
    return 0;
}