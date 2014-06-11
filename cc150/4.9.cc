#include <algorithm>
#include <iostream>
#include "tree.h"

using namespace std;

//solution 1
template <class T>
void findPathHelper(Tree<T> *root, T sum, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->data);
    sum -= root->data;
    if (sum == 0) {
        for_each(path.begin(), path.end(), [](int n) { cout << n << " "; });
        cout << endl;
    }

    findPathHelper(root->left, sum, path);
    findPathHelper(root->right, sum, path);

    path.pop_back();
    sum += root->data;
    if (path.empty()) {  //start from children, but traverse children many times
        findPathHelper(root->left, sum, path);
        findPathHelper(root->right, sum, path);
    }
}

template <class T>
void findPath(Tree<T> *root, T sum)
{
    vector<int> path;
    findPathHelper(root, sum, path);
}

//-----------------------------------------

//solution2
template <class T>
void findPathHelper2(Tree<T> *root, T sum, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->data);
    int path_sum = 0;
    for (auto iter = path.rbegin(); iter != path.rend(); ++iter) {
        path_sum += *iter;
        if (path_sum == sum) {
            //remember the relationship between iterator and reverse_iterator
            for_each(iter.base() - 1, path.end(), [](int n) { cout << n << " "; });
            cout << endl;
        }
    }

    findPathHelper2(root->left, sum, path);
    findPathHelper2(root->right, sum, path);
    path.pop_back();
}

template <class T>
void findPath2(Tree<T> *root, T sum)
{
    vector<int> path;
    findPathHelper2(root, sum, path);
}

int main(int argc, char *argv[])
{
    Tree<int> root(1);
    root.left = new Tree<int>(2);
    root.right = new Tree<int>(3);
    root.left->left = new Tree<int>(1);
    root.left->right = new Tree<int>(-1);
    root.left->right->left = new Tree<int>(1);
    root.right->right = new Tree<int>(0);

    findPath(&root, 3);
    cout << "-----------" << endl;
    findPath2(&root, 3);
    return 0;
}
