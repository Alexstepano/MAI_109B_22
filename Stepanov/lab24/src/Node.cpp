#include "../include/Node.hpp"
Node::Node(const char data) : token(data) {}
Node::Node(const char data, Node *_left, Node *_right) : token(data), left(_left), right(_right) {}
