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
private:
    TreeNode* root = nullptr;
};