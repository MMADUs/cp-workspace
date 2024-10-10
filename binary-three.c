#include <stdio.h>

void func(int n){
    int x = n;
    if (x == 0)
    {
        printf("0");
        return;
    }
    if (x == 1)
    {
        printf("1");
        return;
    }
    //func(x/2);

}

int main(){

    int tc,x,a,b;
    for (int i = 0; i < tc; i++)
    {
        scanf("%d",&x);
        int num[x];
        for (int j = 0; j < x; j++)
        {
            scanf("%d",&num[j]);
            func(num[j]);
        }

    }

    return 0;
}
