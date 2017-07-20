#ifndef __Lispish_Header_LEXER_LEXEME
#define __Lispish_Header_LEXER_LEXEME

#include <string>
#include <boost/variant.hpp>

class Lexeme
{
private:
    enum
    {
        Empty,
        Integer,
        Real,
        Other,
    } m_type;

    boost::variant<bool, long long, long double, std::string> m_content;

public:
    Lexeme();
    Lexeme(long long);
    Lexeme(long double);
    Lexeme(std::string);

    Lexeme& operator=(const long long&);
    Lexeme& operator=(const long double&);
    Lexeme& operator=(const std::string&);

    std::string to_string(bool = false);

    bool is_integer();
    bool is_real();
    bool is_other();

    long long integer_unsafe();
    void integer_unsafe(long long);

    long double real_unsafe();
    void real_unsafe(long double);

    std::string other_unsafe();
    void other_unsafe(std::string);
};

#endif
