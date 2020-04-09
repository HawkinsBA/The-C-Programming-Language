#include <stdio.h>

// Copy input to output, replacing each string of one or more blanks with a single blank
void main() {
    int c, b;

    b = 0; // If b = 0 we haven't encountered a string a blanks yet, if b = 1 we are in a string of blanks
    while ((c = getchar()) != EOF) {
        if (c == ' ' && b == 0) {
            putchar(' ');
            b = 1;
        } else {
            putchar(c);
            if (b == 1) {
                b = 0;
            }
        }
    }
}