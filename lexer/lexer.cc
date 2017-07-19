#include "lexer/lexer.hh"
#include "lexer/token_content.hh"

#include <cctype>

Lexer::Lexer(std::string input) : m_position(0), m_line(0),  m_input(input) {}

std::vector<Token> Lexer::lex()
{
    // start the iterator
    m_iterator = m_input.begin();
    while(not_eof()) {
        // if char is a newline
        if(*m_iterator == '\n')
        {
            increment();
            increment_line();
            continue;
        }
        // skip whitespace
        if(is(' '))
        {
            increment();
            continue;
        }
        // if char is a digit
        if(is_digit())
        {
            // try to extract a number
            try_parse_number();
            continue;
        }
        // if char is a valid first character for an identifier
        if(is_ident_first_char())
        {
            try_parse_ident();
            continue;
        }
        // if char is a parenthesis
        TokenType maybe_paren = check_paren(current_char());
        if(maybe_paren != TokenType::Unknown)
        {
            // extract the parenthesis
            Token token(maybe_paren);
            push_token(token);
            increment();
            continue;
        }
    }

    return m_output;
}

std::string Lexer::dump_tokens()
{
    std::stringstream stream;

    for(Token token: m_output)
    {
        stream << token.to_string() << " ";
    }

    return stream.str();
}

void Lexer::push_token(Token token) { m_output.push_back(token); }

inline char Lexer::current_char() { return *m_iterator; }

inline void Lexer::increment(size_t amount)
{
    m_iterator += amount;
    m_position += amount;
}
inline void Lexer::increment_line(size_t amount) { m_line += amount; }

inline bool Lexer::eof() { return m_iterator >= m_input.end(); }
inline bool Lexer::not_eof() { return m_iterator < m_input.end(); }

bool Lexer::is(char character) { return current_char() == character; }
bool Lexer::is_digit() { return is_digit(*m_iterator); }
bool Lexer::is_digit(char character) { return isdigit(character); }

size_t Lexer::try_parse_int_get_length(std::stringstream& digit_stream)
{
    size_t length = 0;
    while(is_digit() && not_eof())
    {
        digit_stream << current_char();
        increment();
        ++length;
    }
    return length;
}
void Lexer::try_parse_number()
{
    bool is_float = false;
    std::stringstream digit_stream;

    try_parse_int_get_length(digit_stream);
    // check if we have a decimal point
    if(current_char() == '.')
    {
        // parse the rest of the number
        digit_stream << current_char();
        increment();
        try_parse_int_get_length(digit_stream);
        is_float = true;
    }
    std::string number_str = digit_stream.str();

    TokenType type;
    TokenContent lexeme;
    if(is_float)
    {
        type = TokenType::Real;
        lexeme = std::stold(number_str);
    }
    else
    {
        type = TokenType::Integer;
        lexeme = std::stoll(number_str);
    }
    Token token(type, lexeme);
    push_token(token);
}

inline bool isnt_whitespace(char c) { return c != ' ' && c != '\t' && c != '\n'; }
inline bool isnt_parenthesis(char c) { return c != '(' && c != ')'; }
inline bool isnt_delimiter(char c) { return isnt_whitespace(c) && isnt_parenthesis(c) && c != '"'; }
bool Lexer::is_ident_first_char()
{
    return !is_digit() && isnt_delimiter(current_char());
}
bool Lexer::is_ident_char() { return isnt_delimiter(current_char()); }

void Lexer::try_parse_ident()
{
    std::stringstream char_stream;
    while(is_ident_char() && not_eof())
    {
        char_stream << current_char();
        increment();
    }
    std::string ident_str = char_stream.str();

    Token token(TokenType::Ident, ident_str);
    push_token(token);
}
