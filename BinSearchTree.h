#include <iostream>
// the tree node struct
struct TreeNode {
    int info;
    TreeNode *left, *right;
};
// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have search, delete etc.
class BinSearchTree {
public:
    bool insert(int newInt);
    void traverseNodes();
    void traverseNodes(TreeNode* root);

    // more functions
   bool remove(int key);
   int count(TreeNode* rt);
    int sumAll(TreeNode* root);
    int Bheight(TreeNode* root);
    
    // Quiz question
    // print all nodes whose info is less than k
    void BinSearchTree::printLessthank(TreeNode* root, int k) { // move to the .cpp file (leave the heading)
        if (root == nullptr) {
            return;
        }
        printLessthank(root->left);
        if (root->info < k) {
            std::cout << root->info << " ";
        }
        printLessthank(root->right);
    }
private:
    TreeNode* root = nullptr;
};
