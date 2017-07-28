#ifndef __Lispish_Header_LEXER
#define __Lispish_Header_LEXER

#include "lexer/token.hh"

#include <cstddef>
#include <string>
#include <sstream>
#include <vector>
namespace lexer{
    class Lexer
    {
    private:
        size_t m_position;
        size_t m_line;

        std::string m_input;
        std::string::iterator m_iterator;
        std::vector<Token> m_output;

        void push_token(Token);

        inline char current_char();

        inline void increment(size_t amount = 1);
        inline void increment_line(size_t amount = 1);

        inline bool eof();
        inline bool not_eof();

        bool is(char);
        bool isnt(char);
        bool is_digit();
        bool is_digit(char character);

        size_t try_parse_int_get_length(std::stringstream&);
        void try_parse_number();

        bool is_ident_first_char();
        bool is_ident_char();

        void try_parse_ident();

        void skip_rest_of_line();

    public:
        Lexer(std::string);

        std::vector<Token> lex();

        std::string dump_tokens();
    };
}
#endif
