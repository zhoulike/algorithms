#include "tree.h"

template <class T>
Tree<T>* successor(Tree<T> *root)
{
    if (!root)
        return root;
    else if (root->right) {  //minimum of right child
        root = root->right;
        while (root->left)
            root = root->left;
        return root;
    } else {  //first "left" parent
        while (root->parent && root == root->parent->right)
            root = root->parent;
        return root->parent;
    }
}
