#include <stdio.h>
#include <stdlib.h>
#include "../headers/lexer.h"

int main() {
    Token token;
    char* input = "5 + 5";
   
    while(token.type != EOF_TOKEN) {
        token = tokenize(input);
        printf("Token Type: %d, Token Value: %s\n", token.type, token.value);
        free(token.value);
    }
    
    return 0;
}
