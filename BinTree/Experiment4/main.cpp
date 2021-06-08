#include"CreateTree.h"

int main()
{
    BinTree<string> *father = new BinTree<string>;
    creatBinaryTree(father);
    BinTree<string> *son = new BinTree<string>;
    creatBinaryTree(son);
    if(isPartTree(father->getRoot(),son->getRoot()) )cout<<"yes";
    else cout<<"no";
}