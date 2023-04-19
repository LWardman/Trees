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

void Tree::bfs(Node* Root)
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

void Tree::dfs(Node* Root)
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



