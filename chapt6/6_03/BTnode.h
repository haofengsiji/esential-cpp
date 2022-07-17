#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
class BinaryTree;


template <typename valType> class BTnode {
friend class BinaryTree<valType>;
public:
    BTnode(const valType &val);
    void insert_value(const valType &val);
    static void preorder(BTnode *pt, ostream &os);
    static void inorder(BTnode *pt, ostream &os);
    static void postorder(BTnode *pt, ostream &os);
    void remove_value(const valType &val, BTnode *& prev);
private:
    static void lchild_leaf(BTnode<valType> *leaf, BTnode<valType> *subtree);
    static void display_val(BTnode *pt, ostream &os);
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};


template <typename valType>
inline BTnode<valType>::
BTnode(const valType &val) : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}

template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);

    bool empty() { return _root == 0; }
    void clear() {if (_root) {clear(_root); _root = 0;}}
    void insert(const elemType &elem);
    void remove(const elemType &elem);
    void preorder(ostream &os = cout) { BTnode<elemType>::preorder(this->_root, os); }
    void inorder(ostream &os = cout) { BTnode<elemType>::inorder(this->_root, os); }
    void postorder(ostream &os = cout) { BTnode<elemType>::postorder(this->_root, os); }
private:
    void clear(BTnode<elemType>*);
    void remove_root();
    BTnode<elemType> *_root;
    void copy(BTnode<elemType>*tar, BTnode<elemType>*src);
};


template <typename elemType>
inline BinaryTree<elemType>::BinaryTree() : _root(0)
{}


template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs) {
    copy(_root, rhs._root);
}


template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() {clear();}

template <typename elmeType>
inline BinaryTree<elmeType>&
BinaryTree<elmeType>::operator=(const BinaryTree &rhs)
{
    if (this != rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}


template <typename elemType>
inline void
BinaryTree<elemType>::insert(const elemType &elem) {
    if (!_root) {
        _root = new BTnode<elemType>(elem);
    }
    else {
        _root->insert_value(elem);
    }
}


template <typename elemType>
inline void 
BinaryTree<elemType>::
remove(const elemType &elem) {
    if (_root){
        if (_root->_val == elem) {
            remove_root();
        }
        else {
            _root->remove_value(elem, _root);
        }
    }
}

template <typename valType>
void BTnode<valType>::
lchild_leaf(BTnode<valType> *leaf, BTnode<valType> *subtree) {
    while (subtree->_lchild) {
        subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;
}

template <typename valType>
void BTnode<valType>::
preorder(BTnode<valType> *pt, ostream &os) {
    if (pt) {
        display_val(pt, os);
        if (pt->_lchild) preorder(pt->_lchild, os);
        if (pt->_rchild) preorder(pt->_rchild, os);
    }
}

template <typename valType>
void BTnode<valType>::
inorder(BTnode<valType> *pt, ostream &os) {
    if (pt) {
        if (pt->_lchild) preorder(pt->_lchild, os);
        display_val(pt, os);
        if (pt->_rchild) preorder(pt->_rchild, os);
    }
}

template <typename valType>
void BTnode<valType>::
postorder(BTnode<valType> *pt, ostream &os) {
    if (pt) {
        if (pt->_lchild) preorder(pt->_lchild, os);
        if (pt->_rchild) preorder(pt->_rchild, os);
        display_val(pt, os);
    }
}

template <typename valType>
void BTnode<valType>::
display_val(BTnode<valType> *pt, ostream &os) {
    if (pt) {
        os << pt->_val << ' ';
    }
}

template <typename valType>
void BTnode<valType>::
insert_value(const valType &val) {
    if (val == _val) {
        _cnt++;
        return;
    }
    if (val < _val) {
        if (!_lchild) {
            _lchild = new BTnode(val);
        }
        else {
            _lchild->insert_value(val);
        }
    }
    else {
        if (!_rchild) {
            _rchild = new BTnode(val);
        }
        else {
            _rchild->insert_value(val);
        }
    }
}

template <typename valType>
void BTnode<valType>::
remove_value(const valType &val, BTnode *& prev) {
    if (val < _val) {
        if(!_lchild) {
            return;
        }
        else {
            _lchild->remove_value(val, _lchild);
        }
    }
    else if (val > _val) {
        if (!_rchild) {
            return;
        }
        else {
            _rchild->remove_value(val, _rchild);
        }
    }
    else {
        if (_rchild) {
            prev = _rchild;
            if (!prev->_lchild) {
                prev->_lchild = _lchild;
            }
            else BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
        }
        else prev = _lchild;
        delete this;
    }
    
}

template <typename elemType>
void BinaryTree<elemType>::
remove_root()
{
    if (!_root) return;

    BTnode<elemType> *tmp = _root;
    if (_root->_rchild) {
        _root = _root->_rchild;

        if (tmp->_lchild) {
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if (!newlc) {
                _root->_lchild = lc;
            }
            else {
                BTnode<elemType>::lchild_leaf(lc, newlc);
            }
        }
    }
    else {
        _root = _root->_lchild;
    }
    
    delete tmp;
}

template <typename elemType>
void BinaryTree<elemType>::
clear(BTnode<elemType> *pt) {
    if (pt) {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
} 