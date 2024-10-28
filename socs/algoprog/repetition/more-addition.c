#include <stdio.h>

int main(){
    int num, result = 0;
    scanf("%d", &num);
    // if input 3 = 1 + 2 + 3 + 4 = 10
    for(int i = 1; i <= num + 1; i++) {
        result += i;
    }
    printf("%d\n", result);
    return 0;
}
