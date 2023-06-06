#include "../include/Node.hpp"
#include "../include/expressiontree.hpp"
#include <cstdint>
#include <iostream>


int main()
{ std::string expr = "2*1+4/1*1";
    ExpressionTree tree(expr);

    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    tree.lab_task(tree.get_root());
    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    expr = "1*(a*2)+(1^t)*x^9*(1*1*1)*o/1";
    std::cout<<expr<<std::endl;
    ExpressionTree tree2(expr);
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    tree2.lab_task(tree2.get_root());
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    return 0;
}
