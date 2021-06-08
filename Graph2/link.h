template<typename E>class Link{
    public:
        E element;
        Link<E>* next;
        Link(E value , Link<E>_next = nullptr)
        {
            element = value;
            next = _next;
        }
        Link(Link<E>* _next = nullptr)
        {
            next = _next;
        }
};