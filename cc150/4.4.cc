#include <iostream>
#include <vector>
#include <list>
#include "tree.h"

using namespace std;

template <class T>
vector<list<Tree<T>*>> createLevelLinkedList(Tree<T> *root)
{
    vector<list<Tree<T>*>> result;
    list<Tree<T>*> current;
    if (root)
        current.push_back(root);

    while (!current.empty()) {
        result.push_back(current);
        list<Tree<T>*> parents = current;
        current.clear();
        
        for (auto parent: parents) {
            if (parent->left)
                current.push_back(left);
            if (parent->right)
                current.push_back(right);
        }
    }

    return result;
}
