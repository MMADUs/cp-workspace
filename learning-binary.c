#include <stdio.h>

int func(int x, int n){

}


int main(){
    int tc,x,n;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &x,&n);
        printf("%d", func(x,n));
    }


    return 0;
}
