#ifndef LEXER_H
#define LEXER_H

typedef enum {
    INTEGER,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    EOF_TOKEN
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

Token construct_token(TokenType type, char* value);

#endif
