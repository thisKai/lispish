#include "lexer/token.hh"
#include "lexer/lexer.hh"
#include "parser/list.hh"
#include "parser/node.hh"
#include "parser/parser.hh"
#include "repl.hh"

#include <iostream>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>

using namespace lexer;
using namespace parser;

ReplResult repl(const char prompt[])
{
    std::string line;
    while(true)
    {
        line = readline(prompt);
        if(line == "exit")
        {
            std::cout << "Exiting" << std::endl;
            break;
        }

        Lexer lexer(line);
        std::vector<Token> tokens = lexer.lex();
        std::string output = lexer.dump_tokens();
        std::cout << output << std::endl;
        Parser parser(tokens);
        List root = parser.parse();
        std::cout << root.to_string(true) << std::endl;

        add_history(line.c_str());
    }
    return ReplResult::Success;
}
