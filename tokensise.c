#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// List of keywords
const char *keywords[] = {"int", "float", "if", "else", "while", "for", "return", "void", NULL};

// Function to check if a token is a keyword
int isKeyword(char *token) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;  // It's a keyword
        }
    }
    return 0;
}

// Function to check if a token is a constant (number)
int isConstant(char *token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (!isdigit(token[i])) {
            return 0;  // Not a constant
        }
    }
    return 1;  // It's a constant
}

// Function to classify a token
void classifyToken(char *token) {
    if (isKeyword(token)) {
        printf("%s: Keyword\n", token);
    } else if (isConstant(token)) {
        printf("%s: Constant\n", token);
    } else {
        printf("%s: Identifier\n", token);
    }
}

int main() {
    FILE *file;
    char ch;
    char token[MAX_TOKEN_LENGTH];
    int tokenIndex = 0;

    file = fopen("program.c", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            token[tokenIndex++] = ch;  // Collect alphanumeric characters for a token
        } else {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0';
                classifyToken(token);  // Classify the token
                tokenIndex = 0;  // Reset for the next token
            }
        }
    }

    fclose(file);
    return 0;
}