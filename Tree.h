//
// Created by lewis on 18/04/2023.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#include <iostream>
#include <deque>
#include <vector>


/*
 * Nodes hold data in the tree.
 * Includes data to hold and pointers to the left and right subtree.
 */
struct Node {

    int data;
    Node* left;
    Node* right;

    /**
     * Leaves all member variables of Node uninitialised.
     */
    Node()
    = default;

    /**
     * Constructs the data member variable.
     * Leaves left and right subtrees uninitialised.
     */
    explicit Node(int Data)
    {
        data = Data;
        left = nullptr;
        right = nullptr;
    }

    /**
     * Constructs data member variable and point to the left and right subtree.
     */
    Node(int Data, Node* Left, Node* Right)
    {
        data = Data;
        left = Left;
        right = Right;
    }
};


/*
 * Contains functions to build and gather information from a tree.
 */
class Tree {

public:
    // Root of the tree (top element).
    Node* root;

    /**
     * Initialises the root of the tree.
     *
     * @param Root The root of the tree to assign to the member variable root.
     */
    explicit Tree(Node* Root);

    /**
     * Creates a new node in the tree.
     * e.g Root->left = CreateNode(x);
     *
     * @param data integer value to be contained in the new node.
     * @returns The created node.
     */
    static Node* CreateNode(int data);

    /**
     * Prints out the data contained in the tree.
     * Uses In Order traversal to do this.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     */
    void PrintInOrder(Node* Root);

    /**
     * Prints out the data contained in the tree.
     * Uses Pre Order traversal to do this.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     */
    void PrintPreOrder(Node* Root);

    /**
     * Prints out the data contained in the tree.
     * Uses Post Order traversal to do this.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     */
    void PrintPostOrder(Node* Root);

    /**
     * Retrieves the data contained in the tree, using In Order traversal.
     * Useful alternative to printing out all the elements.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     * @param OutVec An empty vector to add values to.
     * @returns The data contained in the tree as an array.
     */
    std::vector<int> GetInOrderArray(Node* Root, std::vector<int> &OutVec);

    /**
     * Retrieves the data contained in the tree, using Pre Order traversal.
     * Useful alternative to printing out all the elements.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     * @param OutVec An empty vector to add values to.
     * @returns The data contained in the tree as an array.
     */
    std::vector<int> GetPreOrderArray(Node* Root, std::vector<int> &OutVec);

    /**
     * Retrieves the data contained in the tree, using Post Order traversal.
     * Useful alternative to printing out all the elements.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     * @param OutVec An empty vector to add values to.
     * @returns The data contained in the tree as an array.
     */
    std::vector<int> GetPostOrderArray(Node* Root, std::vector<int> &OutVec);

    /**
     * Prints out the level order of the tree.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     */
    static void BreadthFirstSearch(Node* Root);

    /**
     * Prints out the Depth order of the tree.
     *
     * @param Root The node to start traversing from. The root of any subtree (including the entire tree).
     */
    static void DepthFirstSearch(Node* Root);

    /**
     * Inverts the tree. Done by interchanging all the left and right subtrees of every node.
     *
     * @param Root The node to start inverting from. The root of any subtree (including the entire tree).
     * @returns The root of the newly inverted tree.
     */
    Node* InvertTree(Node* Root);

    /**
     * Gets the maximum depth of the tree.
     * Depth is defined as the number of node in between and including the current node and the root node.
     *
     * @param Root The node to start searching from. The root of any subtree (including the entire tree).
     * @returns The depth of the tree as an integer.
     */
    int GetMaxDepth(Node* Root);

    /**
     * Utility function for finding the diameter of the tree.
     *
     * @param Root The node to search from. The root of any subtree (including the entire tree).
     * @param Ans A total of the current best answer.
     * @returns The current best diameter of the tree.
     */
    int Height(Node* Root, int &Ans);

    /**
     * Finds the diameter of the tree.
     * Diameter is defined as the length of the longest path between any two nodes in the tree.
     * Does not have to pass through the root.
     *
     * @param Root The node to start searching from. The root of any subtree (including the entire tree).
     * @returns The length of the longest path in the tree.
     */
    int DiameterOfTree(Node* Root);

    /**
     * Checks if two trees are exactly the same.
     *
     * @param Root Root of the first tree.
     * @param OtherRoot Root of the second tree.
     * @returns True or false depending on if the two trees are identical.
     */
    bool IdenticalTree(Node* Root, Node* OtherRoot);

    /**
     * Checks if either tree is a subtree of the other.
     *
     * @param Root Root of the first tree.
     * @param OtherRoot Root of the second tree.
     * @returns True or false depending on if a subtree is present.
     */
    bool IsSubtree(Node* Root, Node* SubRoot);

    /**
     * Collects each level's data as a vector.
     * e.g LevelOrder(Root)[0] returns the root value.
     * e.g LevelOrder(Root)[1] returns two values, the data in the left and right subtrees' root.
     *
     * @param Root The root to start traversing from.
     * @returns a vector of vectors, which contain the data on each level.
     */
    static std::vector<std::vector<int>> LevelOrder(Node* Root);

    /**
     * Determines which nodes would be seen by an observer stood on the right side of the tree.
     *
     * @param Root The root to start traversing from.
     * @returns A vector of the data seen by the observer.
     */
    static std::vector<int> RightSideView(Node* Root);

    /**
     * Determines which nodes would be seen by an observer stood on the left side of the tree.
     *
     * @param Root The root to start traversing from.
     * @returns A vector of the data seen by the observer.
     */
    static std::vector<int> LeftSideView(Node* Root);

    /**
     * A recursive function only called in GoodNodes below.
     *
     * @param Root The root to start traversing from.
     * @param PathMaximum The maximum value in the current path.
     * @param Total A reference to the current number of good nodes.
     */
    void GoodNodesRec(Node* Root, int PathMaximum, int &Total);

    /**
     * Determines the number of good nodes in a tree.
     * A good node is defined as a node whose path to the root contains no number larger than itself.
     *
     * @param Root The root to start traversing from.
     * @returns The number of good nodes in a tree.
     */
    int GoodNodes(Node* Root);

    /**
     * Determines whether the binary search tree is sorted properly.
     *
     * @param Root The root to start checking from.
     * @returns True or false determined by validity of the tree.
     */
    bool ValidateBST(Node* Root);

    /**
     * Determines the K'th smallest element in the tree.
     *
     * @param Root The root to start searching from.
     * @param k The index to find the desired value.
     * @returns The value of the K'th smallest element.
     */
    int KthSmallestEntry(Node* Root, int k);

    /**
     * Builds a new tree based on the Pre Order and In Order traversals of the new tree.
     * Pre Order and In Order traversals must be known before this function is called.
     *
     * @param preorder The Pre Order traversal of the tree to be built.
     * @param inorder The In Order traversal of the tree to be built.
     * @returns The root node of the newly built tree.
     */
    Node* BuildTree(std::vector<int>& preorder, std::vector<int>& inorder);

    /**
     * Recursive function used to help determine the maximum path sum.
     *
     * @param Root The root to start searching from.
     * @param MaxSum The current maximum sum to beat.
     * @returns The maximum path sum.
     */
    int MaxGain(Node* Root, int &MaxSum);

    /**
     * Determines the maximum path sum in the tree.
     *
     * @param Root The root to start searching from.
     * @returns The maximum path sum.
     */
    int MaxPathSum(Node* Root);

};

#endif //TREES_TREE_H
