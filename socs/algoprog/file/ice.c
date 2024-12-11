#include <stdio.h>

int main(){
    FILE *file = fopen("../file/ice.in", "r");
    int tc;
    fscanf(file, "%d", &tc);

    for (int i = 0; i < tc; i++){
        int n;
        fscanf(file, "%d", &n);

        int x[n], sum = 0;
        for (int j = 0; j < n; j++){
            fscanf(file, "%d", &x[j]);
            sum += x[j];
        }

        int area = sum * 4;
        int parimeter = 2 * (n + n + x[0] + x[n - 1]);

        for (int j = 0; j < n - 1; j++){
            int temp = x[j] - x[j + 1];
            if(temp < 0){
                temp *= -1;
            }
            parimeter += temp * 2;
        }
        printf("Case #%d: %d %d\n", i + 1, parimeter, area);
    }
    fclose(file);
    return 0;
}