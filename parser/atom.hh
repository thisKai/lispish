#ifndef __Lispish_Header_PARSER_ATOM
#define __Lispish_Header_PARSER_ATOM

#include "lexer/token_content.hh"

#include <string>

class Atom
{
private:
    TokenContent m_content;
public:
    Atom(TokenContent);
    std::string to_string();
};

#endif
