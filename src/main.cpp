#include <fstream>
#include <iostream>
#include "lexer.h"
#include "parser.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: link <file.link>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string source((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    //for (auto &tok : tokens) {
    //    std::cout << tok.line << ": '" << tok.value
    //            << "' type=" << static_cast<int>(tok.type)
    //            << " column=" << tok.column << "\n";
    //}

    Parser parser(tokens);
    auto program = parser.parse(); // PARSE YOU PARSER.
                            
    program->print();
    return 0;

}

