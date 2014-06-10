#include <algorithm>
#include <climits>
#include "tree.h"

using namespace std;

template <class T>
bool checkBST(Tree<T> *root, int minVal, int maxVal)
{
    if (!root)
        return true;
    else if (root->data <= minVal || root->data > maxVal)  //left <= current < right
        return false;
    else
        return checkBST(root->left, minVal, root->data)
               && checkBST(root->right, root->data, maxVal);
}

template <class T>
bool isBST(Tree<T> *root)
{
    return checkBST(root, INT_MIN, INT_MAX);  //assume T is int
}

template <class T>
bool inorderBST(Tree<T> *root, int &prev)
{
    if (!root)
        return true;
    inorderBST(root->left, prev);
    if (root->data <= prev)  //no duplicates allowed
        return false;
    prev = root->data;
    inorderBST(root->right, prev);
}

template <class T>
bool isBST2(Tree<T> *root)
{
    int tmp = INT_MIN;
    return inorderBST(root, tmp);
}
