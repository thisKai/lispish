#ifndef __Lispish_Header_LEXER_LEXEME
#define __Lispish_Header_LEXER_LEXEME

#include <string>

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

    union
    {
        long long m_integer;
        long double m_real;
        std::string m_other;
    };
    void destroy_other();
    void copy_from(const Lexeme&);

public:
    Lexeme();
    Lexeme(const Lexeme&);
    Lexeme(long long);
    Lexeme(long double);
    Lexeme(std::string);
    ~Lexeme();

    Lexeme& operator=(const Lexeme&);
    Lexeme& operator=(const long long&);
    Lexeme& operator=(const long double&);
    Lexeme& operator=(const std::string&);

    std::string to_string(bool = false);

    bool is_empty() const;
    bool is_integer() const;
    bool is_real() const;
    bool is_other() const;

    long long integer_unsafe() const;
    void integer_unsafe(long long);

    long double real_unsafe() const;
    void real_unsafe(long double);

    std::string other_unsafe() const;
    void other_unsafe(std::string);
};

#endif
