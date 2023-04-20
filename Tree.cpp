//
// Created by lewis on 18/04/2023.
//

#include "Tree.h"
#include <iostream>

Tree::Tree()
{

}

Tree::Tree(Node* Root)
{
    this->root = Root;
}

Node* Tree::CreateNode(int data)
{
    Node* NewNode = new Node();
    NewNode->data = data;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    return NewNode;
}

void Tree::PrintInOrder(Node* Root)
{
    if (!Root) return;

    // First evaluate the left child.
    PrintInOrder(Root->left);

    // Then evaluate the current node.
    std::cout << Root->data << " ";

    // Then evaluate the right child.
    PrintInOrder(Root->right);
}

void Tree::PrintPreOrder(Node* Root)
{
    if (!Root) return;

    // First evaluate the current node.
    std::cout << Root->data << " ";

    // Then evaluate the left child.
    PrintPreOrder(Root->left);

    // Then evaluate the right child.
    PrintPreOrder(Root->right);
}

void Tree::PrintPostOrder(Node* Root)
{
    if (!Root) return;

    // First evaluate the left child.
    PrintPostOrder(Root->left);

    // Then evaluate the right child.
    PrintPostOrder(Root->right);

    // Then evaluate the current node.
    std::cout << Root->data << " ";
}

void Tree::BreadthFirstSearch(Node* Root)
{
    std::deque<Node*> Queue;
    Queue.push_back(Root);

    while (!Queue.empty())
    {
        Node* CurrNode = Queue.front();
        Queue.pop_front();

        std::cout << CurrNode->data << std::endl;

        if (CurrNode->left)
        {
            Queue.push_back(CurrNode->left);
        }
        if (CurrNode->right)
        {
            Queue.push_back(CurrNode->right);
        }
    }
}

void Tree::DepthFirstSearch(Node* Root)
{
    std::deque<Node*> Queue;
    Queue.push_back(Root);

    while (!Queue.empty())
    {
        Node* CurrNode = Queue.front();
        Queue.pop_front();

        std::cout << CurrNode->data << std::endl;

        if (CurrNode->right)
        {
            Queue.push_front(CurrNode->right);
        }
        if (CurrNode->left)
        {
            Queue.push_front(CurrNode->left);
        }

    }
}

Node* Tree::InvertTree(Node* Root) {
    if (root == nullptr) return root;

    Node* placeholder = root->right;
    root->right = root->left;
    root->left = placeholder;
    InvertTree(root->left);
    InvertTree(root->right);

    return root;
}

int Tree::GetMaxDepth(Node* Root) {
    if (root == nullptr) return 0;

    int leftDepth = GetMaxDepth(root->left);
    int rightDepth = GetMaxDepth(root->right);

    return std::max(leftDepth, rightDepth) + 1;
}

int Tree::Height(Node* Root, int &Ans)
{
if(!Root) return 0;

int LeftHeight = Height(Root->left, Ans);
int RightHeight = Height(Root->right, Ans);

Ans = std::max(Ans, 1 + LeftHeight + RightHeight);
return 1 + std::max(LeftHeight, RightHeight);

}

int Tree::DiameterOfTree(Node* Root)
{
    if(!Root) return 0;

    int Ans = 0;
    Height(Root, Ans);
    return Ans - 1;
}



