#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include "tree.h"

using namespace std;

template <class T>
int treeHeight(Tree<T> *root)
{
    if (!root)
        return 0;
    else
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

template <class T>
bool isBalanced1(Tree<T> *root)
{
    if (!root)
        return true;

    if (abs(treeHeight(root->left) - treeHeight(root->right)) > 1)
        return false;
    else
        return isBalanced1(root->left) && isBalanced1(root->right);
}

template <class T>
bool helper2(Tree<T> *root, int &height)
{
    if (!root) {
        height = 0;
        return true;
    }

    int leftHeight, rightHeight;
    if (!helper2(root->left, leftHeight))
        return false;
    
    if (!helper2(root->right, rightHeight))
        return false;

    height = max(leftHeight, rightHeight) + 1;
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    else
        return true;
}

template <class T>
bool isBalanced2(Tree<T> *root)
{
    int tmp;
    if (!root)
        return true;
    else
        return helper2(root, tmp);
}

template <class T>
int helper3(Tree<T> *root)
{
    if (!root)
        return 0;

    int leftHeight = helper3(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = helper3(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    else
        return max(leftHeight, rightHeight) + 1;
}

template <class T>
bool isBalanced3(Tree<T> *root)
{
    return helper3(root) != -1;
}

int main(int argc, char *argv[])
{
    Tree<int> *root = nullptr;
    assert(isBalanced1(root));
    assert(isBalanced2(root));
    assert(isBalanced3(root));
    
    root = new Tree<int>(0);
    assert(isBalanced1(root));
    assert(isBalanced2(root));
    assert(isBalanced3(root));

    root->left = new Tree<int>(1);
    assert(isBalanced1(root));
    assert(isBalanced2(root));
    assert(isBalanced3(root));

    root->left->left = new Tree<int>(2);
    assert(!isBalanced1(root));
    assert(!isBalanced2(root));
    assert(!isBalanced3(root));

    cout << "All passed!" << endl;

    return 0;
}
