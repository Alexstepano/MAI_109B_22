#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include "friend_list_declaration.hpp"
class Node
{
    char token;
    Node *left = nullptr;
    Node *right = nullptr;
    friend class ExpressionTree;

public:
    friend class ExpressionTree;
    Node() = default;
    ~Node() = default;
    Node(const char data);
    Node(const char data, Node *_left, Node *_right);
};
#include "../src/Node.cpp"
#endif// NODE_HPP_INCLUDED
