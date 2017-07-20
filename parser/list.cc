#include "parser/list.hh"

#include <sstream>

std::string List::to_string()
{
    bool first = true;
    std::stringstream stream;
    stream << "list(";
    for(Atom atom: m_items)
    {
        stream << ' ' << atom.to_string() << ' ';

        if(!first) stream << ',';
        first = false;
    }
    stream << ")";
    return stream.str();
}

List& List::operator<<(Atom rhs)
{
    m_items.push_back(rhs);
    return *this;
}
