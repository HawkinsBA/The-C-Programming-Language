#include <stdio.h>

// Count blanks, tabs, and newlines in input
void main() {
    int c, bl, ta, nl;

    bl, ta, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\b') bl++;
        if (c == '\t') ta++;
        if (c == '\n') nl++;
    }

    printf("Blanks: %d\n", bl);
    printf("Tabs: %d\n", ta);
    printf("Newlines: %d", nl);
}