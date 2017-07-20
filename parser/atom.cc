#include "parser/atom.hh"

Atom::Atom(const Atom& atom) {
    if(!atom.m_content->is_empty()) {
        m_content = atom.m_content;
    }
};
Atom::Atom(Lexeme* content) : m_content(content) {};

Lexeme* Atom::content() const
{
    return m_content;
}

std::string Atom::to_string()
{
    return m_content->to_string();
}
