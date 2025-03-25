#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[1000];
    int singleLineComments = 0;
    int multiLineComments = 0;
    int inCommentBlock = 0;

    file = fopen("program.c", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (inCommentBlock) {
            multiLineComments++;
            if (strstr(line, "*/") != NULL) {
                inCommentBlock = 0;
            }
        } else {
            if (strstr(line, "//") != NULL) {
                singleLineComments++;
            } else if (strstr(line, "/*") != NULL) {
                inCommentBlock = 1;
                multiLineComments++;
            }
        }
    }

    fclose(file);
    printf("Single-line comments: %d\n", singleLineComments);
    printf("Multi-line comments: %d\n", multiLineComments);

    return 0;
}