#include "lexer/token.hh"

#include <sstream>

namespace lexer{
    std::string token_type_to_string(TokenType& token_type)
    {
        switch(token_type)
        {
            case TokenType::Unknown: return "Unknown";
            case TokenType::Integer: return "Integer";
            case TokenType::Real: return "Real";
            case TokenType::Ident: return "Ident";
            case TokenType::OpenParen: return "OpenParen";
            case TokenType::CloseParen: return "CloseParen";
        }
    }
    TokenType check_paren(char ch)
    {
        switch(ch)
        {
            case '(': return TokenType::OpenParen;
            case ')': return TokenType::CloseParen;
            default: return TokenType::Unknown;
        }
    }

    Token::Token() : m_type(TokenType::Unknown) {}
    Token::Token(TokenType type) : m_type(type) {}
    Token::Token(Lexeme lexeme) : m_lexeme(lexeme) {}
    Token::Token(TokenType type, Lexeme lexeme) : m_type(type), m_lexeme(lexeme) {}

    std::string Token::to_string()
    {
        switch(m_type)
        {
            case TokenType::OpenParen: return "(";
            case TokenType::CloseParen: return ")";
            default:
                std::stringstream stream;

                stream << "{ "
                            << token_type_to_string(m_type)
                            << " "
                            << m_lexeme.to_string()
                            << " }";

                return stream.str();
        }
    }

    TokenType Token::type()
    {
        return m_type;
    }
    void Token::type(TokenType value)
    {
        m_type = value;
    }

    Lexeme Token::lexeme()
    {
        return m_lexeme;
    }
    void Token::lexeme(Lexeme value)
    {
        m_lexeme = value;
    }
}
