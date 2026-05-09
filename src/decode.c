#include <stdio.h>

void decode(FILE*, FILE*);

int main(int argc, char ** argv) {
    FILE* fin;
    FILE* fout;
    if (argc < 2) {
        fin = stdin;
        fout = stdout;
    } else if (argc == 2) {
        fin = fopen(argv[1], "r");
        fout = stdout;
    } else {
        fin = fopen(argv[1], "r");
        fout = fopen(argv[2], "w");
    }
    decode(fin, fout);
}

void decode(FILE* fin, FILE* fout) {
    char ch;
    int i = 0, working;

    const int delete_character = 0x7F;
    const int first_visible_character = 0x20;
    const int maximum_index_value = 0x7F - 0x20;
    const int normalization_vector = 0x7F - 0x20;

    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= delete_character) {
            fputc(ch, fout);
            continue;
        }
        if (ch < first_visible_character) {
            fputc(ch, fout);
            continue;
        }

        working = ch - i;
        if (working < first_visible_character) {
            ch = working + normalization_vector;
        } else {
            ch = working;
        }

        fputc(ch, fout);

        i++;
        if (i >= maximum_index_value) {
            i = 0;
        }
    }
}
