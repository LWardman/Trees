//
// Created by lewis on 18/04/2023.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#include <iostream>
#include <deque>
#include <vector>

struct Node {

    int data;
    Node* left;
    Node* right;

    Node()
    = default;

    explicit Node(int Data)
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

    explicit Tree(Node* Root);

    static Node* CreateNode(int data);

    void PrintInOrder(Node* Root);

    void PrintPreOrder(Node* Root);

    void PrintPostOrder(Node* Root);

    static void BreadthFirstSearch(Node* Root);

    static void DepthFirstSearch(Node* Root);

    Node* InvertTree(Node* Root);

    int GetMaxDepth(Node* Root);

    int Height(Node* Root, int &Ans);

    int DiameterOfTree(Node* Root);

    bool IdenticalTree(Node* Root, Node* OtherRoot);

    bool IsSubtree(Node* Root, Node* SubRoot);

    static std::vector<std::vector<int>> LevelOrder(Node* Root);

    static std::vector<int> RightSideView(Node* Root);

    static std::vector<int> LeftSideView(Node* Root);

    Node* root;



};









#endif //TREES_TREE_H
