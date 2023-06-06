#include "../include/expressiontree.hpp"

size_t get_priority(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '^') {
        return 3;
    }
    else if (c == '~') {
        return 4;
    }

    return 0;
}

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
std::string ExpressionTree::to_postfix_form(const std::string &expression)
{
    std::string postfix_form = "";
    Vector<char> temp_stack;
    for (size_t i = 0; i < expression.size(); ++i) {
        char temp_char = expression[i];
        if (!is_operator(temp_char) && temp_char != ')' && temp_char != '(') {
            postfix_form += temp_char;
        }
        else if (temp_char == '(') {
            temp_stack.push_back('(');
        }
        else if (temp_char == ')') {
            while (temp_stack.back() != '(') {
                postfix_form += temp_stack.back();
                temp_stack.pop_back();
            }
            temp_stack.pop_back();
        }
        else {
            if (temp_char == '-' && (i == 0 || expression[i - 1] == '(')) temp_char = '~';
            while (!temp_stack.empty() && (get_priority(temp_stack.back()) >= get_priority(temp_char))) {
                postfix_form += temp_stack.back();
                temp_stack.pop_back();
            }
            temp_stack.push_back(temp_char);
        }
    }
    while (!temp_stack.empty()) {
        postfix_form += temp_stack.back();
        temp_stack.pop_back();
    }
    return postfix_form;
}
void ExpressionTree::delete_branch(Node *node)
{
    if (!node) return;
    delete_branch(node->get_left());
    delete_branch(node->get_right());
    delete node;
    node=nullptr;
}
Node *ExpressionTree::create_branch(const std::string &postfix)
{
    if (postfix.length() == 0) return nullptr;

    Vector<Node *> temp_stack;

    for (char c: postfix) {
        if (c == '~') {
            Node *node_x = temp_stack.back();
            temp_stack.pop_back();

            Node *node = new Node('-', nullptr, node_x);
            temp_stack.push_back(node);
        }
        else if (is_operator(c)) {
            Node *node_x = temp_stack.back();
            temp_stack.pop_back();

            Node *node_y = temp_stack.back();
            temp_stack.pop_back();

            Node *node = new Node(c, node_y, node_x);
            temp_stack.push_back(node);
        }
        else {
            temp_stack.push_back(new Node(c));
        }
    }

    return temp_stack.back();
}
ExpressionTree::ExpressionTree(const std::string &expression)
{
    std::string postfix = to_postfix_form(expression);
    root = create_branch(postfix);
}

ExpressionTree::~ExpressionTree()
{
    delete_branch(root);
}

Node *ExpressionTree::get_root() const
{
    return this->root;
}
void ExpressionTree::print_postfix_form(Node *root) const
{
    if (root == nullptr) return;

    print_postfix_form(root->get_left());
    print_postfix_form(root->get_right());
    std::cout << root->get_token();
}
void ExpressionTree::print_infix_form(Node *root) const
{
    if (root == nullptr) return;
    if (is_operator(root->get_token())) {
        std::cout << '(';
    }
    print_infix_form(root->get_left());
    std::cout << root->get_token();
    print_infix_form(root->get_right());
    if (is_operator(root->get_token())) {
        std::cout << ')';
    }
}
void ExpressionTree::print_tree(Node *node, const size_t height) const
{
    if (!(node == nullptr)) {
        print_tree(node->get_right(), height + 1);
        for (int64_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << node->get_token() << '\n';
        print_tree(node->get_left(), height + 1);
    }
}
void ExpressionTree::lab_task(Node *node)
{
    if (!node) return;
    lab_task(node->get_left());
    lab_task(node->get_right());
    Node *temp_node = nullptr;
    if (node->get_token() == '*') {
        if (node->get_left() && node->get_left()->get_token() == '1') {
            delete node->get_left();
            temp_node = node->get_right();
            node->rewrite_node(temp_node);
        }
        else if (node->get_right() && node->get_right()->get_token() == '1') {
            delete node->get_right();
            temp_node = node->get_left();
            node->rewrite_node(temp_node);
        }

    }
}

