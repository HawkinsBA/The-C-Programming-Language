#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float fahr_to_cel(int f);

int main() {
    for (int f = LOWER; f <= UPPER; f = f + STEP) {
        printf("%3d %6.1f\n", f, fahr_to_cel(f));
    }

    return 0;
}

float fahr_to_cel(int f) {
    return (5.0 / 9.0) * (f - 32);
}