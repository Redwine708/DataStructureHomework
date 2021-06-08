#ifndef _BINNODE_
#define _BINNODE_
#include<iostream>
using namespace std;
//节点类定义
template<typename E>class binNode{
    private:
        binNode* _lc;
        binNode* _rc;
        E _elem;
    public:
      +-+*  //默认构造函数
        binNode(E temp , binNode<E>* lc = NULL , binNode<E>* rc = NULL){
            _elem = temp;
            _lc = lc;
            _rc = rc;
        }
        binNode(binNode<E>* lc  = NULL, binNode<E>* rc = NULL){
            _lc = lc;
            _rc = rc;
        }
        E getValue()const{return _elem;}
        binNode<E>* getleft()const{return _lc;}
        binNode<E>* getRight()const{return _rc;}
        void setLeft(binNode<E>* left){
            _lc = left;
        }
        void setRight(binNode<E>* right){
            _rc = right;
        }
        void setValue(const E elem)
        {
            _elem = elem;
        }
        bool isLeaf()
        {
            return (_rc==nullptr&&_lc == nullptr);
        }
};

#endif