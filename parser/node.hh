#ifndef __Lispish_Header_PARSER_NODE
#define __Lispish_Header_PARSER_NODE

#include "parser/atom.hh"

class Node; // forward declare List to get around the circular dependency between List and Node
#include "parser/list.hh"

enum struct NodeType
{
    Empty,
    Atom,
    List,
};

class Node
{
private:
    NodeType m_type;

    void* m_content;

    void free_atom_unsafe();
    Atom* atom_unsafe();
    void atom_unsafe(Atom*);

    void free_list_unsafe();
    List* list_unsafe();
    void list_unsafe(List*);
public:
    Node();
    Node(Atom*);
    Node(List*);
    ~Node();

    std::string to_string();

    Atom* atom();
    void atom(Atom*);

    List* list();
    void list(List*);
};

#endif
