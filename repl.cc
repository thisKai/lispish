#include "lexer/token.hh"
#include "lexer/lexer.hh"
#include "repl.hh"

#include <iostream>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>

ReplResult repl(const char prompt[])
{
    std::string line;
    while(line != "exit") {
        line = readline(prompt);

        Lexer lexer(line);
        std::vector<Token> tokens = lexer.lex();
        std::string output = lexer.dump_tokens();
        std::cout << output << std::endl;

        add_history(line.c_str());
    }
    return ReplResult::Success;
}
