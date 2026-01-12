#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

// --- Math Expression ---
struct Expr {
    virtual ~Expr() = default;
    virtual void print() const = 0; // Fungsi print virtual
};

struct InputExpr : public Expr {
    std::string prompt;
    InputExpr(std::string p) : prompt(p) {}
    
    void print() const override { 
        std::cout << "input(\"" << prompt << "\")"; 
    }
};

struct NumberExpr : public Expr {
    int value;
    NumberExpr(int v) : value(v) {}
    void print() const override { std::cout << value; }
};

struct VariableExpr : public Expr {
    std::string name;
    VariableExpr(std::string n) : name(n) {}
    void print() const override { std::cout << name; }
};

// [NEW] Float
struct FloatExpr : public Expr {
    double value;
    FloatExpr(double v) : value(v) {}
    void print() const override { std::cout << value; }
};

// [NEW] String
struct StringExpr : public Expr {
    std::string value;
    StringExpr(std::string v) : value(v) {}
    void print() const override { std::cout << "\"" << value << "\""; }
};

// [NEW] Char
struct CharExpr : public Expr {
    char value;
    CharExpr(char v) : value(v) {}
    void print() const override { std::cout << "'" << value << "'"; }
};

// [NEW] Bool
struct BoolExpr : public Expr {
    bool value;
    BoolExpr(bool v) : value(v) {}
    void print() const override { std::cout << (value ? "true" : "false"); }
};

struct BinaryExpr : public Expr {
    char op;
    std::unique_ptr<Expr> lhs, rhs;
    BinaryExpr(char o, std::unique_ptr<Expr> l, std::unique_ptr<Expr> r)
        : op(o), lhs(std::move(l)), rhs(std::move(r)) {}
    void print() const override {
        std::cout << "(";
        lhs->print();
        std::cout << " " << op << " ";
        rhs->print();
        std::cout << ")";
    }
};

// --- STATEMENTS ---
struct Stmt {
    virtual ~Stmt() = default;
    virtual void print(int indent = 0) = 0;
};

struct Program {
    std::vector<std::unique_ptr<Stmt>> statements;
    void print() const {
        for (auto& stmt : statements) stmt->print(0);
    }
};

struct SetStmt : public Stmt {
    std::string name;
    std::unique_ptr<Expr> expression;
    SetStmt(const std::string& n, std::unique_ptr<Expr> e) 
        : name(n), expression(std::move(e)) {}
    
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Set: " << name << " = ";
        if (expression) expression->print();
        std::cout << "\n";
    }
};

// --- CONTROL FLOW (WHILE & IF) ---

// [NEW] While Loop
struct WhileStmt : public Stmt {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Stmt>> body;
    
    WhileStmt(std::unique_ptr<Expr> cond) : condition(std::move(cond)) {}
    
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "While: ";
        if(condition) condition->print();
        std::cout << "\n";
        for (auto& s : body) s->print(indent + 2);
    }
};

// [NEW] If Statement (Else/Elif Support)
struct IfStmt : public Stmt {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Stmt>> thenBranch;
    std::vector<std::unique_ptr<Stmt>> elseBranch;

    IfStmt(std::unique_ptr<Expr> cond) : condition(std::move(cond)) {}

    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "If: ";
        if(condition) condition->print();
        std::cout << "\n";
        
        for (auto& s : thenBranch) s->print(indent + 2);

        if (!elseBranch.empty()) {
            std::cout << std::string(indent, ' ') << "Else:\n";
            for (auto& s : elseBranch) s->print(indent + 2);
        }
    }
};

struct ForStmt : public Stmt { 
    std::string iteratorName;
    std::string rangeValue;
    std::vector<std::unique_ptr<Stmt>> body;
    ForStmt(const std::string& iter, const std::string& range) 
        : iteratorName(iter), rangeValue(range) {}
    void print(int indent = 0) override { 
        std::cout << std::string(indent, ' ') << "For: " << iteratorName << " in " << rangeValue << "\n";
        for(auto& s : body) s->print(indent + 2);
    }
};

// --- DECLARATIONS ---

struct AppDecl : public Stmt {
    std::string name;
    std::vector<std::unique_ptr<Stmt>> body;
    AppDecl(const std::string& n) : name(n) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "App: " << name << "\n";
        for (auto& stmt : body) stmt->print(indent + 2);
    }
};

struct WindowDecl : public Stmt {
    std::string name;
    std::vector<std::unique_ptr<Stmt>> body;
    WindowDecl(const std::string& n) : name(n) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Window: " << name << "\n";
        for (auto& stmt : body) stmt->print(indent + 2);
    }
};

struct FuncDecl : public Stmt {
    std::string name;
    std::vector<std::unique_ptr<Stmt>> body;
    FuncDecl(const std::string& n) : name(n) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Func: " << name << "\n";
        for (auto& stmt : body) stmt->print(indent + 2);
    }
};

// --- OTHERS ---

struct PropertyStmt : public Stmt {
    std::string name;
    std::string value;
    PropertyStmt(const std::string& n, const std::string& v) : name(n), value(v) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Property: " << name << " = \"" << value << "\"\n";
    }
};

struct CallStmt : public Stmt {
    std::string func;
    std::unique_ptr<Expr> argExpr;

    CallStmt(const std::string& f, std::unique_ptr<Expr> a) 
        : func(f), argExpr(std::move(a)) {}
    
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Call: " << func << "(";
        if (argExpr) argExpr->print();
        std::cout << ")\n";
    }
};

struct ConnectStmt : public Stmt {
    std::string source;
    std::string event;
    std::string target;
    ConnectStmt(const std::string& s, const std::string& e, const std::string& t)
        : source(s), event(e), target(t) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Connect: " << source << "." << event << " -> " << target << "\n";
    } 
}; 

struct UpdateStmt : public Stmt {
    std::string name;
    std::string op;
    UpdateStmt(const std::string& n, const std::string& o) : name(n), op(o) {}
    void print(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Update: " << name << op << "\n";
    }
};
