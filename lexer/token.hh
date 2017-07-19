#ifndef __Lispish_Header_TOKEN
#define __Lispish_Header_TOKEN

#include "lexer/token_content.hh"
#include <string>

enum struct TokenType
{
    Unknown,
    Integer,
    Real,
    Ident,
    OpenParen,
    CloseParen,
};
std::string token_type_to_string();

TokenType check_paren(char);

class Token
{
private:
    TokenType m_type;

    TokenContent m_lexeme;
public:
    Token();
    Token(TokenType);
    Token(TokenContent);
    Token(TokenType, TokenContent);

    std::string to_string();

    TokenType type();
    void type(TokenType);

    TokenContent lexeme();
    void lexeme(TokenContent);
};

#endif
