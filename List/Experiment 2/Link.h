#ifndef _LINK_
#define _LINK_
#include<iostream>
template<typename E>
class Link
{
    public:
        E element;    //存放数据
        Link<E>* next;
        Link(const E& elemval , Link* nextval = NULL)
        {
            element = elemval;
            next = nextval;
        }
        Link(Link* nextval = NULL)
        {
          next = nextval;
        }

};




#endif