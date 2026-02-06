#pragma once
#include <string>

enum class TokenType {
    // Keywords
    APP, WINDOW, FUNC, EXPOSE, CONNECT, PACKAGE, SH, FOR, IN, SET, 
    WHILE, IF, ELIF, ELSE, IMPORT, RETURN, TRY, CATCH, 
    TRUE, FALSE, CLEAR, CLS, AND, OR, BREAK, CONTINUE, 
    
    CLASS, INIT, NEW, THIS, 
    
    // BITWISE Operators (Hanya Nama Token!)
    BIT_AND, BIT_OR, XOR, LSHIFT, RSHIFT, 
    
    // COMPOUND ASSIGNMENTS (Fitur +=, -=)
    PLUS_PLUS,              // ++
    PLUS_EQ, MINUS_EQ, STAR_EQ, SLASH_EQ, // +=, -=, *=, /=

    // Structural
    INDENT, DEDENT, NEWLINE, EOF_TOKEN, COMMA, COLON,

    // Literals & Identifiers
    IDENTIFIER, STRING, CHAR, TOKEN_NUM, TOKEN_FLOAT,
    
    // Symbols
    LBRACE, RBRACE, LPAREN, RPAREN, LBRACKET, RBRACKET,
    ARROW, DOT, PLUS, MINUS, STAR, SLASH, 
    
    // Comparison & Assignment
    BANG, BANG_EQ,
    ASSIGN,  // =
    LT, GT, EQ_EQ, // <, >, ==
    LE, GE   // <=, >= 
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};
