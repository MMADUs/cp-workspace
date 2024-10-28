#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    for(int i=0; i<t; i++){
        int a, b, c, d;
        double total;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        getchar();
        total = (a * 2.0) + (b * 2.0) + (c * 4.0 / 3.0) + (d * 0.5);
        printf("%.2lf\n", total);
    }
    return 0;
}