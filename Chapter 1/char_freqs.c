#include <stdio.h>
#include <ctype.h>

void draw_horizontal_histogram(int lengths[], int max_length) {
    for (int i = 0; i < max_length; i++) {
        printf("%c | ", 'a' + i);
        for (int j = 0; j < lengths[i]; j++) {
            printf("X");
        }
        printf("\n");
    }
}

void main() {
    int c;
    int freqs[26];

    for (int i = 0; i < 26; i++) {
        
        freqs[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (tolower(c) - 'a' >= 0) {
            freqs[tolower(c) - 'a']++; 
        }
    }

    printf("Horizontal Histogram\n");
    draw_horizontal_histogram(freqs, 26);
}