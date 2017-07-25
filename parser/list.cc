#include "parser/list.hh"

#include <sstream>

std::string List::to_string()
{
    bool first = true;
    std::stringstream stream;
    stream << "list(";
    for(Node node: m_items)
    {
        stream << ' ' << node.to_string() << ' ';

        if(!first) stream << ',';
        first = false;
    }
    stream << ")";
    return stream.str();
}

void List::push(Node rhs)
{
    m_items.push_back(rhs);
}
