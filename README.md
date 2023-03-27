# Data-Structures-and-Algorithms
Practice with different data structures and algorithms

# Binary Trees Notes
You might need to default the left and right pointers to nullptr if an error occurs in the compiler

Binary tree vs Strictly Binary tree vs Binary search tree

queue for trees question that we did on thursday
q.insert(root)
while q != empty {
node = q.remove() --> from front
cout << node -> info;
q.insert(node->left)    if there are children
q.insert(node->right)
}
