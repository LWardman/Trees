//
// Created by lewis on 18/04/2023.
//

#include "Tree.h"
#include <iostream>


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

std::vector<int> Tree::GetInOrderArray(Node* Root, std::vector<int> &OutVec)
{
    if (!Root) return OutVec;

    GetInOrderArray(Root->left, OutVec);
    OutVec.push_back(Root->data);
    GetInOrderArray(Root->right, OutVec);

    return OutVec;
}

std::vector<int> Tree::GetPreOrderArray(Node* Root, std::vector<int> &OutVec)
{
    if (!Root) return OutVec;

    OutVec.push_back(Root->data);
    GetPreOrderArray(Root->left, OutVec);
    GetPreOrderArray(Root->right, OutVec);

    return OutVec;
}

std::vector<int> Tree::GetPostOrderArray(Node* Root, std::vector<int> &OutVec)
{
    if (!Root) return OutVec;

    GetPostOrderArray(Root->left, OutVec);
    GetPostOrderArray(Root->right, OutVec);
    OutVec.push_back(Root->data);

    return OutVec;
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
    if (Root == nullptr) return Root;

    Node* placeholder = Root->right;
    Root->right = Root->left;
    Root->left = placeholder;
    InvertTree(Root->left);
    InvertTree(Root->right);

    return Root;
}

int Tree::GetMaxDepth(Node* Root) {
    if (Root == nullptr) return 0;

    int leftDepth = GetMaxDepth(Root->left);
    int rightDepth = GetMaxDepth(Root->right);

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

bool Tree::IdenticalTree(Node* Root, Node* OtherRoot)
{
    if (!Root && !OtherRoot) return true;
    if (!Root || !OtherRoot) return false;

    bool IdenticalValues = (Root->data == OtherRoot->data);
    bool IdenticalLeftTree = IdenticalTree(Root->left, OtherRoot->left);
    bool IdenticalRightTree = IdenticalTree(Root->right, OtherRoot->right);

    return (IdenticalValues && IdenticalLeftTree && IdenticalRightTree);
}

bool Tree::IsSubtree(Node* Root, Node* SubRoot)
{

    if (!Root) return false;

    if (IdenticalTree(root, SubRoot)) return true;

    bool Left = IdenticalTree(root->left, SubRoot);
    bool Right = IdenticalTree(root->right, SubRoot);

    return Left || Right;
}

std::vector<std::vector<int>> Tree::LevelOrder(Node* Root)
{
    std::vector<std::vector<int>> Ans;

    if (!Root) return Ans;

    std::vector<int> CurrentLevel;

    std::deque<Node*> Queue;
    Queue.push_back(Root);
    Queue.push_back(nullptr);

    while (!Queue.empty())
    {
        Node* Curr = Queue.front();
        Queue.pop_front();

        if (Curr == nullptr)
        {
            Ans.push_back(CurrentLevel);
            CurrentLevel.resize(0);

            if (!Queue.empty())
            {
                Queue.push_back(nullptr);
            }
            continue;
        }

        CurrentLevel.push_back(Curr->data);

        if (Curr->left) Queue.push_back(Curr->left);

        if (Curr->right) Queue.push_back(Curr->right);
    }
    return Ans;
}

std::vector<int> Tree::RightSideView(Node* Root)
{

    std::vector<int> RightView;

    for (std::vector<int> vec : LevelOrder(Root))
    {
        RightView.push_back(vec.back());
    }

    return RightView;
}

std::vector<int> Tree::LeftSideView(Node* Root)
{

    std::vector<int> LeftView;

    for (std::vector<int> vec : LevelOrder(Root))
    {
        LeftView.push_back(vec.front());
    }

    return LeftView;
}

void Tree::GoodNodesRec(Node* Root, int PathMaximum, int &Total)
{
    if(!Root)return;

    if(PathMaximum <= Root->data)
    {
        PathMaximum = Root->data;
        Total++;
    }

    GoodNodesRec(Root->left, PathMaximum, Total);
    GoodNodesRec(Root->right, PathMaximum, Total);
}

int Tree::GoodNodes(Node* Root)
{

    int Total = 0;
    int PathMaximum = INT_MIN;

    GoodNodesRec(Root, PathMaximum, Total);

    return Total;
}

bool Tree::ValidateBST(Node* Root)
{
    std::vector<int> InOrderNumbers;
    GetInOrderArray(Root, InOrderNumbers);

    for(int i = 0; i < InOrderNumbers.size() - 1; i++)
    {
        if (InOrderNumbers[i] >= InOrderNumbers[i+1]) return false;
    }

    return true;
}

int Tree::KthSmallestEntry(Node* Root, int k)
{
    std::vector<int> SortedList;
    GetInOrderArray(Root, SortedList);

    return SortedList[k-1];
}
