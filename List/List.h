/*
 *本数据结构是链表的ADT，只有声明，没有实现，之后再来实现
 *类有构造函数和各种功能函数，来实现列表的插入，删除，遍历，
 *移动元素的操作
 * 
*/

#ifndef _LIST_INCLUDED_
#define _LIST_INCLUDE_


template <typename E> class List //List ADT
{
private: 
    void operator =(const List& ){}     //protect assignment       
    List(const List& ){}        //protect copy destructor
public:
    List(){;}  //default constructor
    virtual ~List() {}//Base destructor

    //Clear constens from the list , to make it empty
    virtual void clear ()= 0;

    //insert an element at the current location .
    //item : The element to be inserted 
    virtual void insert (const E& it) = 0 ;

    //append an element at the end of the list.
    //item : The element to be appended
    virtual void append (const E& it) = 0 ;

    //Remove and return the curent element
    //Retrurn : the element that was removed
    virtual E remove() = 0;

    //Set the current position to the start of the list .
    virtual void moveToStart () = 0;

    //Set the curent posion to the end of the list .
    virtual void moveToEnd () = 0;
    
    //Move the current position one step left . No change
    //if already at the beginning
    virtual void prev ()  = 0;

    //Move the current posion one step right . No change
    //if already at the end
    virtual void next () = 0;

    //Return : the number of elements in the list
    virtual int length () const = 0;
    
    //Return : The position of the current element
    virtual int currPos () const = 0 ;

    //Set current posion
    //pos : The position to make current
    virtual void moveToPos (int Pos) = 0 ;

    //Return : The current element
    virtual const E& getValue() const = 0;


};
 

#endif