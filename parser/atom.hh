#ifndef __Lispish_Header_PARSER_ATOM
#define __Lispish_Header_PARSER_ATOM

#include "lexer/token_content.hh"

#include <string>

class Atom
{
private:
    Lexeme m_content;
public:
    Atom(Lexeme);
    std::string to_string();
};

#endif
