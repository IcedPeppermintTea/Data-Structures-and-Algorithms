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
