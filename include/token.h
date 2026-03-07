#pragma once
#include <string>

enum class TokenType {
    // Keywords
    APP, WINDOW, FUNC, EXPOSE, CONNECT, PACKAGE, SH, FOR, IN, SET, 
<<<<<<< HEAD
    WHILE, IF, ELIF, ELSE, IMPORT, RETURN, TRY, CATCH, 
    TRUE, FALSE, CLEAR, CLS, AND, OR, BREAK, CONTINUE, 
    
    CLASS, INIT, NEW, THIS, 
    
    // BITWISE Operators (Hanya Nama Token!)
    BIT_AND, BIT_OR, XOR, LSHIFT, RSHIFT, 
    
    // COMPOUND ASSIGNMENTS (Fitur +=, -=)
    PLUS_PLUS,              // ++
    PLUS_EQ, MINUS_EQ, STAR_EQ, SLASH_EQ, // +=, -=, *=, /=
=======
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
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c

    // Structural
    INDENT, DEDENT, NEWLINE, EOF_TOKEN, COMMA, COLON,

    // Literals & Identifiers
    IDENTIFIER, STRING, CHAR, TOKEN_NUM, TOKEN_FLOAT,
    
    // Symbols
<<<<<<< HEAD
    LBRACE, RBRACE, LPAREN, RPAREN, LBRACKET, RBRACKET,
    ARROW, DOT, PLUS, MINUS, STAR, SLASH, 
    
    // Comparison & Assignment
    BANG, BANG_EQ,
    ASSIGN,  // =
    LT, GT, EQ_EQ, // <, >, ==
    LE, GE   // <=, >= 
=======
    LBRACE, RBRACE,    
    LPAREN, RPAREN,    
    ARROW, DOT, PLUS, MINUS, STAR, SLASH, PLUS_PLUS,
    ASSIGN, 
    LT, GT, EQ_EQ 
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};
