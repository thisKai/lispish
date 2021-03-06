#ifndef __Lispish_Header_PARSER_NODE
#define __Lispish_Header_PARSER_NODE

#include "parser/atom.hh"

namespace parser{
    class Node; // forward declare List to get around the circular dependency between List and Node
}
#include "parser/list.hh"

namespace parser{
    using namespace lexer;

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
        Atom* atom_unsafe() const;
        void atom_unsafe(Atom*);

        void free_list_unsafe();
        List* list_unsafe() const;
        void list_unsafe(List*);
    public:
        Node();
        Node(const Node&);
        Node(Atom*);
        Node(List*);
        ~Node();

        std::string to_string(bool block = false);

        Atom* atom();
        void atom(Atom*);

        List* list();
        void list(List*);
    };
}
#endif
