#ifndef __Lispish_Header_PARSER
#define __Lispish_Header_PARSER

#include "lexer/token.hh"
#include "lexer/lexeme.hh"
#include "parser/atom.hh"
#include "parser/list.hh"

#include <vector>
#include <stack>

class Parser
{
private:
    std::vector<Token> m_input;
    std::vector<Token>::iterator m_iterator;
    size_t m_level;
    std::stack<List> m_lists;

    inline Token current_token();

    inline bool not_eof();

    inline void increment(size_t = 1);

    List current_list();
    void begin_list();
    void end_list();

public:
    Parser(std::vector< Token >&);

    List parse();
};

#endif
