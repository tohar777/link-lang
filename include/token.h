#pragma once
#include <string>

enum class TokenType {
    // Keywords
    APP, WINDOW, FUNC, EXPOSE, CONNECT, PACKAGE, SH, FOR, IN, SET, 
    WHILE, IF, ELIF, ELSE,
    TRUE, FALSE, // [NEW] Boolean keywords

    // Structural
    INDENT, DEDENT, NEWLINE, EOF_TOKEN,

    // Literals & Identifiers
    IDENTIFIER, 
    STRING,     // "abc" atau 'abc'
    CHAR,       // 'a'
    TOKEN_NUM,  // 123
    TOKEN_FLOAT,// 12.34 [NEW]

    // Symbols
    LBRACE, RBRACE,    
    LPAREN, RPAREN,    
    ARROW, DOT, PLUS, MINUS, STAR, SLASH, PLUS_PLUS,
    ASSIGN, 
    LT, GT, EQ_EQ 
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};
