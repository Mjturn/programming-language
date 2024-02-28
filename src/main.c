#include <stdio.h>
#include <stdlib.h>
#include "../headers/lexer.h"

int main() {
    Token token = construct_token(INTEGER, "5");
    printf("Token Type: %d\nToken Value: %s\n", token.type, token.value);
    free(token.value);
    return 0;
}
