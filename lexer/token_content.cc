#include "lexer/token_content.hh"

#include <sstream>

TokenContent::TokenContent()
{
    m_type = Empty;
}

TokenContent::TokenContent(long long l_integer)
{
    integer_unsafe(l_integer);
}
TokenContent::TokenContent(long double l_real)
{
    m_content = l_real;
    m_type = Real;
}
TokenContent::TokenContent(std::string l_other)
{
    m_content = l_other;
    m_type = Other;
}

template <typename T>
std::string token_content_string(const char left_delimiter[], T content, const char right_delimiter[])
{
    std::stringstream stream;

    stream << left_delimiter << content << right_delimiter;

    return stream.str();
}
std::string TokenContent::to_string(bool show_delimiters)
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

bool TokenContent::is_integer() { return m_type == Integer; }
bool TokenContent::is_real() { return m_type == Real; }
bool TokenContent::is_other() { return m_type == Other; }

long long TokenContent::integer_unsafe() { return boost::get<long long>(m_content); }
void TokenContent::integer_unsafe(long long value)
{
    m_type = Integer;
    m_content = value;
}

long double TokenContent::real_unsafe() { return boost::get<long double>(m_content); }
void TokenContent::real_unsafe(long double l_real)
{
    m_content = l_real;
    m_type = Real;
}

std::string TokenContent::other_unsafe() { return boost::get<std::string>(m_content); }
void TokenContent::other_unsafe(std::string l_other)
{
    m_content = l_other;
    m_type = Other;
}


TokenContent& TokenContent::operator=(const long long& l_integer)
{
    integer_unsafe(l_integer);
    return *this;
}
TokenContent& TokenContent::operator=(const long double& l_real)
{
    real_unsafe(l_real);
    return *this;
}
TokenContent& TokenContent::operator=(const std::string& l_other)
{
    other_unsafe(l_other);
    return *this;
}
