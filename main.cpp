#include "Tree.h"

int main() {
    // Level 1
    Node* Root = CreateNode(1);

    // Level 2
    Root->left = CreateNode(2);
    Root->right = CreateNode(3);

    // Level 3
    Root->left->left = CreateNode(4);
    Root->left->right = CreateNode(5);
    Root->right->left = CreateNode(6);
    Root->right->right = CreateNode(7);

    // Level 4
    Root->left->left->left = CreateNode(8);
    Root->left->left->right = CreateNode(9);
    Root->left->right->left = CreateNode(10);
    Root->left->right->right = CreateNode(11);
    Root->right->left->left = CreateNode(12);
    Root->right->left->right = CreateNode(13);
    Root->right->right->left = CreateNode(14);
    Root->right->right->right = CreateNode(15);


    //bfs(Root);

    dfs(Root);

    //PrintTree(Root);

    return 0;
}
