#ifndef _BINTREE_
#define _BINTREE_
#include"Node.h"
#include<iostream>
using namespace std;
template<typename E>class BinTree{
    private:
        binNode<E>* root;
        void clear(binNode<E>*r)
        {
            if(r == nullptr)return;
            clear(r->left());
            clear(r->right());
            delete r;
        }
    public:
        BinTree()
        { 
            root = new binNode<E>();
           
        }
        ~BinTree()
        {
            clear();
        }
        binNode<E>* getRoot()
        {
            return root;
        }
        void setRoot(binNode<E>* r)
        {
            root = r;
        }

};

#endif
