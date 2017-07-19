#ifndef __Lispish_Header_TOKEN_CONTENT
#define __Lispish_Header_TOKEN_CONTENT

#include <string>
#include <boost/variant.hpp>

class TokenContent
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
    TokenContent();
    TokenContent(long long);
    TokenContent(long double);
    TokenContent(std::string);

    TokenContent& operator=(const long long&);
    TokenContent& operator=(const long double&);
    TokenContent& operator=(const std::string&);

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
