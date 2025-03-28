#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int lines = 0;

    file = fopen("program.c", "r"); // Open file for reading
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    printf("Total number of lines: %d\n", lines);

    return 0;
}