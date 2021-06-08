#ifndef _LIST_
#define _LIST_
template<typename E>
class List
{
    private:
        List(const List& ){}
        void operator = (const List&){}
    private:
        List(){}
        virtual ~List(){}
        virtual void clear() = 0;
        virtual void next() = 0;
        virtual void prev() = 0;
        virtual int length()const = 0 ;
        virtual E& getValue()const = 0;
        virtual E remove() = 0;
        virtual void append(const E& ) = 0;
        virtual void insert(const E& ) = 0;
        virtual int currPos()const = 0;
        virtual void moveToPos(int ) = 0;
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;        
};

#endif //List ADT