#include "parser/list.hh"

#include <sstream>

namespace parser{
    std::string List::to_string(bool block)
    {
        std::stringstream stream;
        if(block)
        {
            for(Node node: m_items)
            {
                stream << node.to_string() << std::endl;
            }
        }
        else
        {
            bool first = true;
            stream << "list(";
            for(Node node: m_items)
            {
                if(!first && !block) stream << ',';
                stream << ' ' << node.to_string() << ' ';
                first = false;
            }
            stream << ")";
        }
        return stream.str();
    }

    void List::push(Node rhs)
    {
        m_items.push_back(rhs);
    }
}
