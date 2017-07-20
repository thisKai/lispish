#include "lexer/lexeme.hh"

#include <sstream>

Lexeme::Lexeme()
{
    m_type = Empty;
}
void Lexeme::copy_from(const Lexeme& original)
{
    if(original.is_integer())
    {
        integer_unsafe(original.integer_unsafe());
    }
    else if(original.is_real())
    {
        real_unsafe(original.real_unsafe());
    }
    else if(original.is_other())
    {
        other_unsafe(original.other_unsafe());
    }
    else
    {
        destroy_other();
        m_type = Empty;
    }
}
// copy constructor
Lexeme::Lexeme(const Lexeme& original)
{
    copy_from(original);
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

void Lexeme::destroy_other()
{
    if(m_type == Other)
    {
        m_other.~basic_string<char>();
    }
}
Lexeme::~Lexeme()
{
    destroy_other();
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

bool Lexeme::is_empty() const { return m_type == Empty; }
bool Lexeme::is_integer() const { return m_type == Integer; }
bool Lexeme::is_real() const { return m_type == Real; }
bool Lexeme::is_other() const { return m_type == Other; }

long long Lexeme::integer_unsafe() const { return m_integer; }
void Lexeme::integer_unsafe(long long value)
{
    destroy_other();
    m_integer = value;
    m_type = Integer;
}

long double Lexeme::real_unsafe() const { return m_real; }
void Lexeme::real_unsafe(long double value)
{
    destroy_other();
    m_real = value;
    m_type = Real;
}

std::string Lexeme::other_unsafe() const { return m_other; }
void Lexeme::other_unsafe(std::string value)
{
    m_other = value;
    m_type = Other;
}


Lexeme& Lexeme::operator=(const Lexeme& original)
{
    copy_from(original);
    return *this;
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
