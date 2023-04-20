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

    Node()
    {

    }

    Node(int Data)
    {
        data = Data;
        left = nullptr;
        right = nullptr;
    }

    Node(int Data, Node* Left, Node* Right)
    {
        data = Data;
        left = Left;
        right = Right;
    }
};

class Tree {

public:

    Tree();

    Tree(Node* Root);

    Node* CreateNode(int data);

    void PrintInOrder(Node* Root);

    void PrintPreOrder(Node* Root);

    void PrintPostOrder(Node* Root);

    void BreadthFirstSearch(Node* Root);

    void DepthFirstSearch(Node* Root);

    Node* InvertTree(Node* Root);

    int GetMaxDepth(Node* Root);

    int Height(Node* Root, int &Ans);

    int DiameterOfTree(Node* Root);

    Node* root;



};









#endif //TREES_TREE_H
