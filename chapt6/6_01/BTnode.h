#pragma once

#include <iostream>
#include <vector>

template <typename Type>
class BinaryTree;


template <typename valType> class BTnode {
public:

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};


template <typename elemType>
class BinaryTree {
public:
    //
private:

    BTnode<elemType> *_root;
};
