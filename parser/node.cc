#include "parser/node.hh"

Node::Node() : m_type(NodeType::Empty) {}
Node::Node(const Node& original)
{
    m_type = original.m_type;
    switch(m_type)
    {
        case NodeType::Atom:
            atom_unsafe(new Atom(*original.atom_unsafe()));
            break;
        case NodeType::List:
            list_unsafe(new List(*original.list_unsafe()));
            break;
        default:
            m_type = NodeType::Empty;
            break;
    }
}
Node::Node(Atom* content) : m_type(NodeType::Atom), m_content(content) {}
Node::Node(List* content) : m_type(NodeType::List), m_content(content) {}
Node::~Node()
{
    switch(m_type)
    {
        case NodeType::Atom:
            free_atom_unsafe();
            break;
        case NodeType::List:
            free_list_unsafe();
            break;
    }
}

std::string Node::to_string()
{
    switch(m_type)
    {
        case NodeType::Atom:
            return atom_unsafe()->to_string();
        case NodeType::List:
            return list_unsafe()->to_string();
        default:
            return "";
    }
}

Atom* Node::atom_unsafe() const
{
    return (Atom*)m_content;
}
void Node::atom_unsafe(Atom* value)
{
    m_type = NodeType::Atom;
    m_content = value;
}
Atom* Node::atom()
{
    if(m_type == NodeType::Atom)
    {
        return atom_unsafe();
    }
    else
    {
        return nullptr;
    }
}
void Node::atom(Atom* value)
{
    if(m_type == NodeType::List)
    {
        free_list_unsafe();
    }
    m_content = value;
}
void Node::free_atom_unsafe()
{
    Atom* old_atom = atom_unsafe();
    delete old_atom;
}

List* Node::list_unsafe() const
{
    return (List*)m_content;
}
void Node::list_unsafe(List* value)
{
    m_type = NodeType::List;
    m_content = value;
}
List* Node::list()
{
    if(m_type == NodeType::List)
    {
        return list_unsafe();
    }
    else
    {
        return nullptr;
    }
}
void Node::list(List* value)
{
    if(m_type == NodeType::Atom)
    {
        free_atom_unsafe();
    }
    m_content = value;
}
void Node::free_list_unsafe()
{
    List* old_list = list_unsafe();
    delete old_list;
}
