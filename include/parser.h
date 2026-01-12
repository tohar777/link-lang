#pragma once
#include <vector>
#include <memory>
#include "token.h"
#include "ast.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Program> parse();

private:
    const std::vector<Token>& tokens;
    size_t current;

    const Token& peek() const;
    const Token& advance();
    bool match(TokenType type);
    const Token& consume(TokenType type, const std::string& err);

    std::unique_ptr<Stmt> parseStatement();
    std::unique_ptr<AppDecl> parseApp();
    std::unique_ptr<WindowDecl> parseWindow();
    std::unique_ptr<FuncDecl> parseFunc();
    
    // --- UPDATE STRUKTUR BARU ---
    std::unique_ptr<Stmt> parseFor(); 
    std::unique_ptr<Stmt> parseWhile(); 
    std::unique_ptr<Stmt> parseIf(); 
    std::unique_ptr<Stmt> parseSet();

    // Hirarki Ekspresi (Urutan sangat penting!)
    std::unique_ptr<Expr> parseExpression(); // Level 1: Logic (<, >, ==)
    std::unique_ptr<Expr> parseAdditive();   // Level 2: Addition (+, -) [NEW]
    std::unique_ptr<Expr> parseTerm();       // Level 3: Multiplication (*, /)
    std::unique_ptr<Expr> parsePrimary();    // Level 4: Numbers, Identifiers, Parentheses
    // ----------------------------
    
    std::unique_ptr<CallStmt> parseCall();
    std::unique_ptr<ConnectStmt> parseConnect();

    bool isAtEnd() const;
};
