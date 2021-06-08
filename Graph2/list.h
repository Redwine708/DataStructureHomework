#include"Link.h"
template<typename E>
class List
{
    private:
        void operator = (const List&){}
        List(const List&){}
    public:
        List(){}
        virtual ~List(){}

        virtual void clear() = 0;
        virtual E remove() = 0;
        virtual void append(E& it) = 0;
        virtual void insert(E& it) = 0;

        virtual void moveToStart()const = 0;
        virtual void moveToEnd()const = 0;
        virtual void moveToPos(const int pos) = 0;

        virtual void prev()const = 0;
        virtual void next()const = 0;
        virtual int length() const = 0;
        virtual int currPos() = 0;
        virtual E getValue()const = 0;

};