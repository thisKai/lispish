#include "lexer/lexeme.hh"

#include <sstream>

Lexeme::Lexeme()
{
    m_type = Empty;
}

Lexeme::Lexeme(long long l_integer)
{
    integer_unsafe(l_integer);
}
Lexeme::Lexeme(long double l_real)
{
    real_unsafe(l_real);
}
Lexeme::Lexeme(std::string l_other)
{
    other_unsafe(l_other);
}

template <typename T>
std::string token_content_string(const char left_delimiter[], T content, const char right_delimiter[])
{
    std::stringstream stream;

    stream << left_delimiter << content << right_delimiter;

    return stream.str();
}
std::string Lexeme::to_string(bool show_delimiters)
{
    switch(m_type)
    {
        case Empty: return "Empty";
        case Integer: return token_content_string("", integer_unsafe(), "");
        case Real: return token_content_string("", real_unsafe(), "");
        case Other:
            const char* delimiter = show_delimiters ? "\"" : "";
            return token_content_string(delimiter, other_unsafe(), delimiter);
    }
}

bool Lexeme::is_integer() { return m_type == Integer; }
bool Lexeme::is_real() { return m_type == Real; }
bool Lexeme::is_other() { return m_type == Other; }

long long Lexeme::integer_unsafe() { return boost::get<long long>(m_content); }
void Lexeme::integer_unsafe(long long value)
{
    m_type = Integer;
    m_content = value;
}

long double Lexeme::real_unsafe() { return boost::get<long double>(m_content); }
void Lexeme::real_unsafe(long double l_real)
{
    m_content = l_real;
    m_type = Real;
}

std::string Lexeme::other_unsafe() { return boost::get<std::string>(m_content); }
void Lexeme::other_unsafe(std::string l_other)
{
    m_content = l_other;
    m_type = Other;
}


Lexeme& Lexeme::operator=(const long long& l_integer)
{
    integer_unsafe(l_integer);
    return *this;
}
Lexeme& Lexeme::operator=(const long double& l_real)
{
    real_unsafe(l_real);
    return *this;
}
Lexeme& Lexeme::operator=(const std::string& l_other)
{
    other_unsafe(l_other);
    return *this;
}
