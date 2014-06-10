#include <vector>
#include <cassert>
#include <iostream>
#include "tree.h"

using namespace std;

template <class T>
Tree<typename T::value_type>* helper(T first, T last)
{
    typedef typename T::value_type U;

    if (first >= last)
        return nullptr;
    
    auto mid = first + ((last - first) >> 1);
    Tree<U> *node = new Tree<U>(*mid);
    node->left = helper(first, mid);
    node->right = helper(mid + 1, last);
    return node;
}

template <class T>
Tree<T>* createTree(vector<T> &vec)
{
    return helper(vec.begin(), vec.end());
}

template <class T>
void inOrder(Tree<T> *root)
{
    if(!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(int argc, char *argv[])
{
    vector<int> v1;
    assert(createTree(v1) == nullptr);

    vector<int> v2 = {1};
    inOrder(createTree(v2));
    cout << endl;

    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    inOrder(createTree(v3));
    cout << endl;

    return 0;
}
