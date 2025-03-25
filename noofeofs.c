#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int lines = 0;
    int isEmptyLine;

    file = fopen("program.c", "r"); // Open file for reading
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        isEmptyLine = 1;  // Assume line is empty initially
        while (ch != '\n' && ch != EOF) {
            if (!isspace(ch)) {  // Check if there is a non-whitespace character
                isEmptyLine = 0;
            }
            ch = fgetc(file);
        }
        if (!isEmptyLine) {
            lines++;
        }
    }

    fclose(file);
    printf("Total number of non-empty lines: %d\n", lines);

    return 0;
}