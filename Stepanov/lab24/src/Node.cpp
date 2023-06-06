#include "../include/Node.hpp"
Node::Node(const char data) : token(data) {}
Node::Node(const char data, Node *_left, Node *_right) : token(data), left(_left), right(_right) {}
char Node::get_token() const
{
    return token;
}
Node *Node::get_left() const
{
    return left;
}
Node *Node::get_right() const
{
    return right;
}
void Node::rewrite_node(Node *temp_node)
{
    this->token = temp_node->token;
    this->right = temp_node->right;
    this->left = temp_node->left;
}
