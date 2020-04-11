#include <stdio.h>

#define IN  1
#define OUT 0

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

// A program which prints a vertical & horizontal histogram of the lengths of words in its input
void main() {
    int c, state, cur_word_length, max_word_length;
    int word_lengths[50]; 
    /* Hopefully, we don't encounter a word longer than 50 characters. 
       The longest word in the Oxford English Dictionary, pneumonoultramicroscopicsilicovolcanoconiosis, is 45 characters.
       https://en.wikipedia.org/wiki/Pneumonoultramicroscopicsilicovolcanoconiosis */

    for (int i = 0; i < 50; i++) {
        word_lengths[i] = 0;
    }
    state = OUT;
    cur_word_length = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (cur_word_length > max_word_length) {
                max_word_length = cur_word_length;
                word_lengths[cur_word_length]++;
                cur_word_length = 0;
                state = OUT;
            }  else {
                word_lengths[cur_word_length]++;
                cur_word_length = 0;
                state = OUT;
            }
        } else {
            cur_word_length++;
        }
    }

    printf("Horizontal Histogram\n");
    draw_horizontal_histogram(word_lengths, max_word_length);
    printf("Vertical Histogram\n");
    draw_vertical_histogram(word_lengths, max_word_length);
}
