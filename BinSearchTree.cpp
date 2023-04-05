#include "BinSearchTree.h"

// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root; // p is the root
    TreeNode* q = nullptr; // q is the parent of p, p starts at root
    // might need to default right and left to null in .h
    // looking for the node to see if it is already in the list
    while (p != nullptr) { // as long as tree not empty and not the end
        if (p->info == newInt) { // if the int is equal to the value of the root
            return false;
        }
        q = p; // q gets the value of the root, before p is updated
        if (newInt < p->info) { // if newInt is less than the root
            p = p->left; // move to the left
        }
        else { // if it is more than the root
            p = p->right; // move to the right
        }
    }
    // the search failed, we insert it now
    TreeNode* v = new TreeNode; // new node
    v->info = newInt; // give v the value of the int you want to insert
    if (q == nullptr) { // if the tree is empty
        std::cout << "Insert at root " << v->info << std::endl;
        root = v; // root becomes the value you want to insert
    }
    else if (newInt < q->info) { // if the int is less than the root
        std::cout << "Insert " << v->info << " left to " << q->info << std::endl;
        q->left = v; // the value is inserted at the left
    }
    else{ // if the int is more than the root
        std::cout << "Insert " << v->info << " right to " << q->info << std::endl;
        q->right = v; // the value is inserted to the right
    }
    return true;
}

void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}
void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}

// more functions
bool BinSearchTree::remove(int key) {
    TreeNode* p = root; // the node to be deleted
    TreeNode* q = nullptr; // p's parent
    // search for the node
    while (p != nullptr && p->info != key) {
        q = p;
        if (key < p->info){
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    // once we exit the loop
    TreeNode* rp; // new node to be p's replacement
    // find rp for p when p has at MOST one child
    if (p->left == nullptr) { // if no child on the left
        rp = p->right; // child on the right (ONE child)
    }
    else if (p->right == nullptr) { // if no child on the right
        rp = p->left; // one child on the left
    }
    else { // if two children
        TreeNode* f = p; // f is set to the parent of rp (p)
        rp = p->right; // rp is set as the inorder successor of p 
        TreeNode* s = rp->left;
        while(s != nullptr) {
            f = rp;
            rp = s;
            s = rp->left;
        }
        if (f != p) {
            f->left = rp->right;
            rp->right = p->right;
        }
        rp->left = p->left;
    }
    if (q == nullptr) {
        root = rp;
    }
    else if (p == q->left) {
        q->left = rp;
    }
    else {
        q->right = rp;
    }
    delete p;
    return rp != nullptr;
}

// count the nodes in the tree
int BinSearchTree::count(TreeNode* rt) {
    // Base case
    if (rt = nullptr) { // Nothing to count because the tree is empty
        return 0;
    }
    return 1 + count(rt->left) + count(rt->right);
}
// sum of the values for all nodes
int BinSearchTree::sumAll(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->info + sumAll(root->left) + sumAll(root->right);
}

int BinSearchTree::Bheight(TreeNode* root){
    if (root == nullptr) {
        return 0;
    }
    return std::max(1 + Bheight(root->left), 1 + Bheight(root->right));
}

// recursive practice

// Find minimum element in a BST (no recursion)
int BinSearchTree::FindMin(TreeNode* root) {
    if (root == nullptr) { // if tree is empty
        return 0;
    }
    // if not empty, traverse the list for the minimum value
    while (root->left != nullptr) {
        root = root->info;
    }
    return root->info;
}

// Find minimum element in a BST (with recursion)
int BinSearchTree::FindMin(TreeNode* root) {
    if (root == nullptr) { // if tree is empty
        return 0;
    }
    // if the left subtree node is empty
    else if (root->left == nullptr) {
        return root->info;
    }
    return FindMin(root->left);
}

// Find maximumn element in a BINARY TREE
int BinSearchTree::FindBinaryMax(TreeNode* root) {
    int max_val = 0;
    if (root == nullptr) { // if tree is empty
        return max_val;
    }
    int root_val = root->info;
    int left_val = FindBinaryMax(root->left); // find largest value of the left
    int right_val = FindBinaryMax(root->right); // find largest value of the right
    
    // compare
    if (left_val > root_val) {
        max_val = left_val;
    }
    if (right_val > root_val) {
        max_val = right_val;
    }
    return max_val;
}

// count all the nodes in a tree
int BinSearchTree::count(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

// return the sum of al the nodes of the binary tree
int BinSearchTree::sumAll(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->info + sumAll(root->left) + sumAll(root->right);
}

// find the height of a binary tree
int BinSearchTree::getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_max = 1 + getHeight(root->left);
    int right_max = 1 + getHeight(root->right);
    if (left_max > right_max) {
        return left_max;
    }
    else if (right_max > left_max) {
        return right_max;
    }
    return max(left_max, right_max); // same as if else 
}

// display the depths of all the leaves
void BinSearchTree::displayLeafDepths(TreeNode* root, int depth) {
    if (root == nullptr) { // if empty
        exit(1);
    }
    // if end of the tree
    else if (root->left == nullptr && root->right == nullptr) {
        std::cout << depth << endl; 
    }
    else { // not yet end of tree
        displayLeafDepths(root->left, depth + 1);
        displayLeafDepths(root->right, depth + 1);
}

// find if a binary tree is strictly binary
bool BinSearchTree::isStrictlyBinary(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    else if (root->left != nullptr && root->right != nullptr) {
        bool leftBinary = isStrictlyBinary(TreeNode* root-left);
        bool rightBinary = isStrictlyBinary(TreeNode* root->right);
        return leftBinary && rightBinary;
    }
    else {
        return false;
    }
}
    
// Delete a node from a Binary Search Tree
TreeNode* BinSearchTree::delete(TreeNode* root, int data) {
    // if tree is empty
    if (root == nullptr) {
        return null;
    }
    // if the node is not found at root, which side of tree we should go to
    else if (data < root-info) { // if the node we are looking for is smaller than the root, go to the left
        root->left = Delete(root->left, data); // update the left
    }
    else if (data > root->info) { // if the node we are looking for is larger than the root, go to the right
        root->right = Delete(root->right, data); // update the right
    }
    else { // if the node we are looking for is found ( == )
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root; // delete the node
            root = nullptr; // set the pointer to null
        }
        // Case 2: One child
        else if (root->left = nullptr) { // if only the left child is null (one child on the right)
            TreeNode* temp = root; // temporary pointer to store the value of the node we are trying to delete
            root = root->right; // move the root pointer to the right child, right child becomes the root of the subtree
            delete temp; // delete the node
        }
        else if (root->right = nullpt) { // if only right child is null (one child on the left)
            TreeNode* temp = root; // temporary pointer to store the value of the node we are trying to delete
            root = root->left; // move the root pointer to the left child, left child becomes the root of the subtree
            delete temp; // delete the node
        }
        // Case 3: TWO children
        else { // we can use either the successor or predecessor, using successor here
            TreeNode *temp = FindMin(root->right);
            root->info = temp->info; // set the node you are trying to delete to the minimum value
            root->right = Delete(root->right, temp->info); // delete the node from the right subtree
                
        }
    }
    return root;
}
