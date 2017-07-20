#ifndef __Lispish_Header_PARSER_ATOM
#define __Lispish_Header_PARSER_ATOM

#include "lexer/lexeme.hh"

#include <string>

class Atom
{
private:
    Lexeme* m_content;
public:
    Atom(const Atom&);
    Atom(Lexeme*);

    Lexeme* content() const;
    std::string to_string();
};

#endif
