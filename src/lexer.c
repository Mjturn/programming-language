#include <string.h>
#include "../headers/lexer.h"

Token construct_token(TokenType type, char* value) {
    Token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}
