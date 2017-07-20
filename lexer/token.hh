#ifndef __Lispish_Header_LEXER_TOKEN
#define __Lispish_Header_LEXER_TOKEN

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

    Lexeme m_lexeme;
public:
    Token();
    Token(TokenType);
    Token(Lexeme);
    Token(TokenType, Lexeme);

    std::string to_string();

    TokenType type();
    void type(TokenType);

    Lexeme lexeme();
    void lexeme(Lexeme);
};

#endif
