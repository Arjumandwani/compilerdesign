#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *token;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    token = strtok(str, " \n");  // Tokenize the string using space and newline as delimiters
    while (token != NULL) {
        printf("%s\n", token);  // Print each token
        token = strtok(NULL, " \n");
    }

    return 0;
}
