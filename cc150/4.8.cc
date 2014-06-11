#include <iostream>
#include <cassert>
#include <string>
#include "tree.h"

using namespace std;

//solution1
template <class T>
bool sameTree(Tree<T> *root1, Tree<T> *root2)
{
    if (!root1 && !root2)
        return true;
    else if (root1 && root2 && root1->data == root2->data)
        return sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    else
        return false;
}

template <class T>
bool containsTree(Tree<T> *root1, Tree<T> *root2)  //is root1 contains root2?
{
    if (root2 == nullptr)  //any tree has an empty subtree
        return true;
    else if (root1 == nullptr)
        return false;
    else {
        if (sameTree(root1, root2)) //sameTree first check whether root1->data == root2->data
            return true;
        else
            return containsTree(root1->left, root2) || containsTree(root1->right, root2);
    }
}

//-------------------

//solution2
template <class T>  //for simplicity, assume T is string
void inorder(Tree<T> *root, string &sequence)
{
    //avoid such situation
    //  3  and 3
    //3          3
    if (!root) { 
        sequence += ",";  //, equals to nullptr
        return;
    }
    inorder(root->left, sequence);
    sequence += root->data;
    inorder(root->right, sequence);
}

template <class T>  //for simplicity, assume T is string
void preorder(Tree<T> *root, string &sequence)
{
    //avoid such situation
    //  3  and 3
    //3          3
    if (!root) { 
        sequence += ",";  //, equals to nullptr
        return;
    }
    sequence += root->data;
    preorder(root->left, sequence);
    preorder(root->right, sequence);
}

template <class T>
bool containsTree2(Tree<T> *root1, Tree<T> *root2)
{
    if (!root2)
        return true;
    else if (!root1)
        return false;
    else {
        string inorder1, preorder1;
        inorder(root1, inorder1);
        preorder(root1, preorder1);

        string inorder2, preorder2;
        inorder(root2, inorder2);
        preorder(root2, preorder2);

        return inorder1.find(inorder2) != string::npos &&
               preorder1.find(preorder2) != string::npos;
    }
}

int main(int argc, char *argv[])
{
    Tree<string> root("0"), root2("100"), root3("3");
    root.left = new Tree<string>("1");
    root.left->parent = &root;
    root.right = new Tree<string>("2");
    root.right->parent = &root;
    root.left->left = new Tree<string>("3");
    root.left->left->parent = root.left;
    root.left->right = new Tree<string>("4");
    root.left->right->parent = root.left;

    assert(containsTree(&root, &root));
    assert(containsTree(&root, root.left));
    assert(containsTree(&root, root.left->right));
    assert(!containsTree(&root, &root2));
    assert(containsTree(&root, &root3));

    assert(containsTree2(&root, &root));
    assert(containsTree2(&root, root.left));
    assert(containsTree2(&root, root.left->right));
    assert(!containsTree2(&root, &root2));
    assert(containsTree2(&root, &root3));

    cout << "all passed!" << endl;
    
    return 0;
}
