#include "parser/parser.hh"
#include "parser/node.hh"

Parser::Parser(std::vector<Token>& tokens) : m_input(tokens) { }

List Parser::parse()
{
    m_iterator = m_input.begin();
    begin_list();
    while(not_eof())
    {
        switch(current_token().type()){
            case  TokenType::OpenParen:
                begin_list();
                increment();
                continue;
            case TokenType::CloseParen:
                end_list();
                increment();
                continue;
            default:
                Node node(new Atom(new Lexeme(current_token().lexeme())));
                current_list().push(node);
                increment();
                continue;
        }
    }
    return current_list();
}

inline Token Parser::current_token() { return *m_iterator; }

inline bool Parser::not_eof() { return m_iterator < m_input.end(); }

inline void Parser::increment(size_t amount) { m_iterator += amount; }

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
    Node node(finished_list);
    current_list().push(node);
}
