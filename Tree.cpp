//
// Created by lewis on 18/04/2023.
//

#include "Tree.h"

Tree::Tree(int Depth)
{

}

void Tree::PrintTree(Node* Root)
{
    if (!Root) return;

    std::cout << Root->data << std::endl;
    PrintTree(Root->left);
    PrintTree(Root->right);
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

Node* Tree::CreateNode(int data)
{
    Node* NewNode = new Node();
    NewNode->data = data;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    return NewNode;
}

