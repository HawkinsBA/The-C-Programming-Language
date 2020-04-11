#include <stdio.h>
#include <ctype.h>

void draw_horizontal_histogram(int lengths[], int max_length) {
    for (int i = 1; i <= max_length; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < lengths[i]; j++) {
            printf("X");
        }
        printf("\n");
    }
}

void draw_vertical_histogram(int lengths[], int max_length) {
    int max_height = 0;

    for (int i = 0; i < max_length; i++) {
        if (lengths[i] > max_height) {
            max_height = lengths[i];
        }
    }

    for (int i = max_height; i >= 1; i--) {
        for (int j = 1; j <= max_length; j++) {
            if (lengths[j] >= i) {
                printf(" XX ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    for (int i = 1; i <= max_length; i++) {
        printf("----");
    }

    printf("\n");

    for (int i = 1; i <= max_length; i++) {
        printf("%4d", i);
    }
}

void main() {
    int c;
    int freqs[26];

    for (int i = 0; i < sizeof(freqs); i++) {
        freqs[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        freqs[tolower(c) - 'a']++; 
    }

    printf("Horizontal Histogram\n");
    draw_horizontal_histogram(freqs, sizeof(freqs));
    printf("Vertical Histogram\n");
    draw_vertical_histogram(freqs, sizeof(freqs));
}