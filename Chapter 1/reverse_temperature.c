#include <stdio.h>

void main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;

    printf("%3s %6s\n", "C", "F");
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}