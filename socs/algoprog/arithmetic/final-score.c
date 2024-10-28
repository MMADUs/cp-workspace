#include <stdio.h>

int main(){
    int assignment, mid, final;
    scanf("%d", &assignment);
    scanf("%d", &mid);
    scanf("%d", &final);

    float finalscore = 0.2 * assignment + 0.3 * mid + 0.5 * final;
    printf("%.2f\n", finalscore);
    return 0;
}