#include <iostream>
#include "BinSearchTree.h"

int main()
{
    BinSearchTree st = BinSearchTree(); // the tree object
    st.insert(8); //the root
// where will each of this go in the BST?
    st.insert(3);
    st.insert(11);
    st.insert(9);
    st.insert(10);
    st.insert(14);
// now traverse
    std::cout << "inorder traversal: ";
    st.traverseNodes();
}
