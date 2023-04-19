#include "Tree.h"

int main() {

    Node* Root = new Node(1);

    Tree* tree = new Tree(Root);

    // Level 2
    tree->root->left = tree->CreateNode(2);
    tree->root->right = tree->CreateNode(3);

    // Level 3
    tree->root->left->left = tree->CreateNode(4);
    tree->root->left->right = tree->CreateNode(5);
    tree->root->right->left = tree->CreateNode(6);
    tree->root->right->right = tree->CreateNode(7);

    // Level 4
    tree->root->left->left->left = tree->CreateNode(8);
    tree->root->left->left->right = tree->CreateNode(9);
    tree->root->left->right->left = tree->CreateNode(10);
    tree->root->left->right->right = tree->CreateNode(11);
    tree->root->right->left->left = tree->CreateNode(12);
    tree->root->right->left->right = tree->CreateNode(13);
    tree->root->right->right->left = tree->CreateNode(14);
    tree->root->right->right->right = tree->CreateNode(15);


    //bfs(Root);

    //dfs(Root);

    tree->PrintInOrder(Root);

    return 0;
}
