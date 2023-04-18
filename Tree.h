//
// Created by lewis on 18/04/2023.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#include <iostream>
#include <deque>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Tree {

public:

    Tree(int Depth);

    void PrintTree(Node* Root);

    void bfs(Node* Root);

    void dfs(Node* Root);

private:

    Node* CreateNode(int data);

};









#endif //TREES_TREE_H
