#include <iostream>
#include <utility>
#include "tree.h"

using namespace std;

//solution1
//tree node has parent
template <class T>
Tree<T>* firstAncestor(Tree<T> *node1, Tree<T> *node2)
{
    if (!node1 || !node2)
        return nullptr;

    //find root
    Tree<T> *root = node1;
    while (root->parent)
        root = root->parent;

    if (root == node1 || root == node2)
        return root;

    //turns tree into looped linked list
    root->parent = node1;  
    Tree<T> *slow, *fast;
    slow = fast = node2;

    while (fast && fast->parent) {
        slow = slow->parent;
        fast = fast->parent->parent;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->parent) { //nodes come from different tree;
        root->parent = nullptr;  //recover
        return nullptr;
    }

    slow = node2;
    while (slow != fast) {
        slow = slow->parent;
        fast = fast->parent;
    }

    root->parent = nullptr;
    return slow;
}

//the following solutions assume tree node does not have parent
//solution2
template <class T>
Tree<T>* helper2(Tree<T> *root, Tree<T> *node1, Tree<T> *node2,
                 Tree<T>* &ancestor1, Tree<T>* &ancestor2)
{
    //ancestor1: ancestor of node1
    //ancestor2: ancestor of node2
    if (!root) {
        ancestor1 = ancestor2 = nullptr;
        return nullptr;
    }

    Tree<T> *result, *tmp1, *tmp2, *tmp3, *tmp4;
    tmp1 = tmp2 = tmp3 = tmp4 = nullptr;

    if ((result = helper2(root->left, node1, node2, tmp1, tmp2)))
        return result;
    if ((result = helper2(root->right, node1, node2, tmp3, tmp4)))
        return result;

    if (tmp1 || tmp3 || root == node1)
        ancestor1 = root;
    if (tmp2 || tmp4 || root == node2)
        ancestor2 = root;

    if (ancestor1 == ancestor2)
        return ancestor1;
    else
        return nullptr;
}

template <class T>
Tree<T>* firstAncestor2(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    Tree<T> *tmp1 = nullptr, *tmp2 = nullptr;
    if (!root || !node1 || !node2)
        return nullptr;
    else if (root == node1 || root == node2)
        return root;
    else
        return helper2(root, node1, node2, tmp1, tmp2);
}

//solution3: variation of solution 2
template <class T>
pair<Tree<T>*, Tree<T>*> helper3(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    typedef pair<Tree<T>*, Tree<T>*> ANCESTOR;
    if (!root)
        return {nullptr, nullptr};

    ANCESTOR result1 = helper3(root->left, node1, node2);
    if (result1.first && result1.second)
        return result1.first == result1.second? result1: ANCESTOR{root, root};

    ANCESTOR result2 = helper3(root->right, node1, node2);
    if (result2.first && result2.second)
        return result2.first == result2.second? result1: ANCESTOR{root, root};

    ANCESTOR result = {nullptr, nullptr};
    if (result1.first || result2.first || root == node1)
        result.first = root;
    if (result1.second || result2.second || root == node2)
        result.second = root;

    if (result.first && result.second)
        result = {root, root};

    return result;
}

template <class T>
Tree<T>* firstAncestor3(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    if (!root || !node1 || !node2)
        return nullptr;
    else if (root == node1 || root == node2)
        return root;
    else {
        auto result = helper3(root, node1, node2);
        if (result.first == result.second)
            return result.first;
        else
            return nullptr;
    }
}

//solution 4: from the book
template <class T>
bool covers(Tree<T> *root, Tree<T> *node)
{
    if (!root)
        return false;
    else if (root == node)
        return true;
    else
        return covers(root->left, node) || covers(root->right, node);
}

template <class T>
Tree<T>* helper4(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    if (!root)
        return nullptr;
    else if (root == node1 || root == node2)
        return root;

    bool onLeft1 = covers(root->left, node1),
         onLeft2 = covers(root->left, node2);

    if (onLeft1 != onLeft2)
        return root;
    Tree<T> *child = onLeft1? root->left: root->right;
    return helper4(child, node1, node2);
}

template <class T>
Tree<T>* firstAncestor4(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    if (!covers(root, node1) || !covers(root, node2))
        return nullptr;
    else
        return helper4(root, node1, node2);
}

template <class T>
void test(Tree<T> *node1, Tree<T> *node2)
{
    Tree<T> *ancestor = firstAncestor(node1, node2);
    if (ancestor)
        cout << "first ancestor: " << ancestor->data << endl;
    else
        cout << "no common ancestor!" << endl;
}

template <class T>
void test2(Tree<T> *root, Tree<T> *node1, Tree<T> *node2)
{
    Tree<T> *ancestor = firstAncestor2(root, node1, node2);
    if (ancestor)
        cout << "first ancestor: " << ancestor->data << endl;
    else
        cout << "no common ancestor!" << endl;
}

int main(int argc, char *argv[])
{
    Tree<int> root(0);
    root.left = new Tree<int>(1);
    root.left->parent = &root;
    root.right = new Tree<int>(2);
    root.right->parent = &root;
    root.left->left = new Tree<int>(3);
    root.left->left->parent = root.left;
    root.left->right = new Tree<int>(4);
    root.left->right->parent = root.left;

    Tree<int> other(100);

    test(&root, other.left);  //nullptr
    test(root.left->left, root.right);  //0
    test(root.left->left, root.left->right); //1
    test(&other, &other); //100
    test(root.left->left, &other); //nullptr

    test2(&root, &root, other.left);  //nullptr
    test2(&root, root.left->left, root.right);  //0
    test2(&root, root.left->left, root.left->right); //1
    test2(&other, &other, &other); //100
    test2(&root, root.left->left, &other); //nullptr
    return 0;
}
