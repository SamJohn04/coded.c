#include <stdio.h>

void encode(FILE *);

int main(int argc, char ** argv) {
    FILE * fin;
    if (argc < 2) {
        fin = stdin;
    } else {
        fin = fopen(argv[1], "r");
    }
    encode(fin);
}

void encode(FILE * fin) {
    char ch;
    int i = 0, working;

    const int delete_character = 0x7F;
    const int first_visible_character = 0x20;
    const int maximum_index_value = 0x7F - 0x20;
    const int normalization_vector = 0x7F - 0x20;

    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= delete_character) {
            putchar(ch);
            continue;
        }
        if (ch < first_visible_character) {
            putchar(ch);
            continue;
        }

        working = ch + i;
        if (working >= delete_character) {
            ch = working - normalization_vector;
        } else {
            ch = working;
        }

        putchar(ch);

        i++;
        if (i >= maximum_index_value) {
            i = 0;
        }
    }
}
