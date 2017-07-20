#include "parser/atom.hh"

Atom::Atom(Lexeme content) : m_content(content) {};

std::string Atom::to_string()
{
    return m_content.to_string();
}
