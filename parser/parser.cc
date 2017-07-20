#include "parser/parser.hh"

Parser::Parser(std::vector<Token>& tokens) : m_input(tokens), m_level(0) { }

List Parser::parse()
{
    m_iterator = m_input.begin();
    begin_list();
    while(not_eof())
    {
        switch(current_token().type()){
            case  TokenType::OpenParen:
                begin_list();
                continue;
            case TokenType::CloseParen:
                end_list();
                continue;
            default:
                Atom atom = current_token().lexeme();
                current_list() << atom;
                continue;
        }
    }
    return current_list();
}

inline Token Parser::current_token() { *m_iterator; }

inline bool Parser::not_eof() { return m_iterator < m_input.end(); }

inline void Parser::increment(size_t) { ++m_iterator; }

List Parser::current_list()
{
    return m_lists.top();
}
void Parser::begin_list() {
    List new_list;
    m_lists.push(new_list);
}
void Parser::end_list() {
    List finished_list = current_list();
    m_lists.pop();
}
