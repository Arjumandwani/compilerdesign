#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {"int", "float", "if", "else", "while", "return", NULL};

int isKeyword(char *token) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<');
}

void tokenize(char *code) {
    char token[100];
    int i = 0, j = 0;
    
    while (code[i] != '\0') {
        if (isalnum(code[i]) || code[i] == '_') {
            token[j++] = code[i++];
        } else if (isOperator(code[i])) {
            token[j] = '\0';
            if (j > 0) {
                printf("%s: Identifier\n", token);
                j = 0;
            }
            printf("%c: Operator\n", code[i++]);
        } else if (code[i] == ' ' || code[i] == '\n') {
            if (j > 0) {
                token[j] = '\0';
                if (isKeyword(token)) {
                    printf("%s: Keyword\n", token);
                } else {
                    printf("%s: Identifier\n", token);
                }
                j = 0;
            }
            i++;
        } else {
            i++;
        }
    }
}

int main() {
    char code[100];
    
    printf("Enter code snippet: ");
    fgets(code, sizeof(code), stdin);
    
    tokenize(code);
    
    return 0;
}
