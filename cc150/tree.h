#ifndef TREE_H
#define TREE_H

template <class T>
struct Tree {
    T data;
    Tree *left;
    Tree *right;

    Tree(T val) :data(val), left(nullptr), right(nullptr) {}
};

#endif
