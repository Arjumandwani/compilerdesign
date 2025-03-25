#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {  // Starts with letter or underscore
        return 0;
    }
    for (int i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {  // Only letters, digits, or underscores
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strlen(str) - 1] = '\0';  // Remove the newline character
    
    if (isValidIdentifier(str)) {
        printf("%s is a valid identifier\n", str);
    } else {
        printf("%s is not a valid identifier\n", str);
    }
    
    return 0;
}
