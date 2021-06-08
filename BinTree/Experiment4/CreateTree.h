#ifndef _CREATETREE_
#define _CREATETREE_
#include"BinTree.h"
#include<string>
#include<iostream>
using namespace std;
template<typename E>
binNode<E>*  creatBinaryTree(string  s[],  int  &x,int  n)//构建二叉树的主函数，根据先序遍历，采用递归思想构建
{
        if  (s[x]  == "#" )
                return  NULL;
        else
        {
                binNode<E>*node  =  new  binNode<E>(s[x]);
                x  =  x  +  1;
                if  (x  <  n)
                node->setLeft(creatBinaryTree<E>(s,  x,n));
                x  =  x  +  1;
                if  (x  <  n)
                node->setRight(creatBinaryTree<E>(s,  x,n));
                return  node;
        }
}

void  creatBinaryTree(BinTree<string>*BT)//构建二叉树的函数，包含了上面的构建二叉树的主函数，仅仅起到了在主函数中简洁一些的作用
{
        //cout  <<  "现在进入构建二叉树程序......"  <<  endl;
        //cout  <<  "请输入二叉树有多少个结点(空结点也计算其中)"  <<  endl;
       string tree;
       cin>>tree;
       int n = tree.length();
        //cout  <<  "请按preorder顺序输入，遇到NULL请输入'/',用空格隔开或者回车隔开均可以"  <<  endl;
        string*s  =  new  string[n];
        for  (int  i  =  0;  i  <  n;  i++)
        {
                s[i] = tree[i];
        }
        int  now  =  0;
        BT->setRoot(creatBinaryTree<string>(s,  now,  n));
}

template<typename E>
bool isPart(binNode<E>* root1 , binNode<E>* root2)
{
    if(root2 == NULL)return true;
    if(root1 == NULL)return false;
    if(root1->getValue() != root2 ->getValue())return false;
    return isPart(root1->getleft(),root2->getleft()) && 
        isPart(root1->getRight() , root2 -> getRight());
}

template<typename E>
bool isPartTree(binNode<E>* rootA , binNode<E>* rootB)
{
    bool result = false;
    if(rootA!=NULL&&rootB!=NULL)
    {
        if(rootA->getValue() == rootB->getValue())
        result = isPart(rootA,rootB);
        if(!result) result = isPartTree(rootA->getleft(),rootB);
        if(!result) result = isPartTree(rootA->getRight(), rootB);
    }
    return result;
}
#endif