#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/lexer.h"

Token construct_token(TokenType type, char* value) {
    Token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}

Token tokenize(char* input) {
    static unsigned int index = 0;

    while(isspace(input[index])) {
        index++;
    }

    switch(input[index]) {
        case '+':
            index++;
            return construct_token(ADD, "+");
        case '-':
            index++;
            return construct_token(SUBTRACT, "-");
        case '*':
            index++;
            return construct_token(MULTIPLY, "*");
        case '/':
            index++;
            return construct_token(DIVIDE, "/");
        case '(':
            index++;
            return construct_token(LEFT_PARENTHESIS, "(");
        case ')':
            index++;
            return construct_token(RIGHT_PARENTHESIS, ")");
        case '\0':
            return construct_token(EOF_TOKEN, "");
        default:
            if (isdigit(input[index])) {
                char value[100];
                unsigned int i = 0;
                
                while(isdigit(input[index])) {
                    value[i++] = input[index++];
                }

                value[i] = '\0';
                return construct_token(INTEGER, value);
            } else {
                fprintf(stderr, "Unexpected character: %c\n", input[index]);
                exit(1);
            }
    }
}
