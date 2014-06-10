#ifndef TREE_H
#define TREE_H

template <class T>
struct Tree {
    T data;
    Tree *parent;
    Tree *left;
    Tree *right;

    Tree(T val) :data(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

#endif
