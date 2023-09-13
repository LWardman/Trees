#include "Tree.h"

int main() {

    Node* Root = new Node(1);

    Tree* tree = new Tree(Root);

    std::vector<int> PreOrder = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};

    std::vector<int> InOrder = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};

    tree->root = tree->BuildTree(PreOrder, InOrder);

    Tree::PrintInOrder(tree->root);
    std::cout << std::endl;
    Tree::PrintPostOrder(tree->root);
    std::cout << std::endl;
    Tree::PrintPreOrder(tree->root);
    return 0;
}
