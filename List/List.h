/*
 *This is abstract data structure for list
 *To finish my first homework in CG
 *To protect the class, I set copy contructor and assignment as private  
 */

#ifndef _LIST_
#define _LIST_
template<typename E>
class List
{
    public:
        List();
        virtual ~List(){}
        virtual void clear () = 0;
        virtual E remove() = 0;
};


#endif