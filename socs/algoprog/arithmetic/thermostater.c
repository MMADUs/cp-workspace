#include <stdio.h>

int main() {
    float input;
    for (int i = 0; i < 3; i++) {
        scanf("%f", &input);
        float reamur = input * 0.8;
        float fahrenheit = (input * 9 / 5) + 32;
        float kelvin = input + 273;
        printf("%.2f %.2f %.2f\n", reamur, fahrenheit, kelvin);
    }
    return 0;
}
