#ifndef _LINK_
#define _LINK_
template<typename E>
class Link
{
    public:
        E element;
        Link<E>* next;
        Link(const E& vale,Link<E>* _next = nullptr)
        {
            element = value;
            next = _next;
        }
        Link(Link<E>* _next = nullptr)
        {
            next = _next;
        }
    
};
#endif //Link ADT