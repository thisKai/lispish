#ifndef __Lispish_Header_PARSER_LIST
#define __Lispish_Header_PARSER_LIST

#include "parser/atom.hh"

#include <vector>
#include <string>

class List
{
private:
    std::vector<Atom> m_items;
public:
    std::string to_string();

    List& operator<<(Atom);
};

#endif
