#ifndef __Lispish_Header_PARSER_LIST
#define __Lispish_Header_PARSER_LIST

#include "parser/atom.hh"

class List; // forward declare List to get around the circular dependency between List and Node
#include "parser/node.hh"

#include <vector>
#include <string>

class List
{
private:
    std::vector<Node> m_items;
public:
    std::string to_string();

    void push(Node);
};

#endif
