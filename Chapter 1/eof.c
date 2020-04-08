#include <stdio.h>

void main() {
    int c;

    // On Windows, the EOF character is CTRL+Z
    printf("The integer value of EOF is %d.\n", EOF);
    while (c != EOF) {
        printf("%d\n", (c = getchar()) != EOF);
    }
}