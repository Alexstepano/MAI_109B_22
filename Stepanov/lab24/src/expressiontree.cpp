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
    delete_branch(node->left);
    delete_branch(node->right);
    delete node;
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

    print_postfix_form(root->left);
    print_postfix_form(root->right);
    std::cout << root->token;
}
void ExpressionTree::print_infix_form(Node *root) const
{
    if (root == nullptr) return;
    if (is_operator(root->token)) {
        std::cout << '(';
    }
    print_infix_form(root->left);
    std::cout << root->token;
    print_infix_form(root->right);
    if (is_operator(root->token)) {
        std::cout << ')';
    }
}
void ExpressionTree::print_tree(Node *node, const size_t height) const
{
    if (!(node == nullptr)) {
        print_tree(node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << node->token << '\n';
        print_tree(node->left, height + 1);
    }
}
void ExpressionTree::clear_multiply_ones(Node *node)
{
    if (!node) return;
    clear_multiply_ones(node->left);
    clear_multiply_ones(node->right);
    bool shift_flag = false;
    Node *temp_node = nullptr;
    if (node->token == '*') {
        if (node->left && node->left->token == '1') {
            delete node->left;
            temp_node = node->right;
            shift_flag = true;
        }
        else if (node->right && node->right->token == '1') {
            delete node->right;
            temp_node = node->left;
            shift_flag = true;
        }
        if (shift_flag) {
            node->token = temp_node->token;
            node->right = temp_node->right;
            node->left = temp_node->left;
            delete temp_node;
            shift_flag = false;
        }
    }
}

