#include"list.h"
#include<assert.h>
template<typename E>
class LList : public List{
    private:
        Link<E>* head;
        Link<E>* curr;
        Link<E>* tail;
        int cnt;
        void removeall()
        {
            while(head != nullptr)
            {
                curr = head;
                head = head -> next;
                delete curr;
            }
        }
        void init()
        {
            head = curr = tail = new Link<E>;
            cnt = 0;
        }
    
    public:
        LList(){init();}
        ~LList(){removeall();}
        
        void clear()
        {
            removeall();
            init();
        }

        void moveToStart()const
        {
            curr = head;
        }

        void moveToEnd()const
        {
            curr = tail;
        }
        
        void moveToPos(int t)
        {
            curr = head;
            for(int i = 0  ; i < t ; i++)
            {
                curr = curr->next;
            }
        }
        int currPos()
        {
            Link<E>* tmp = head;
            int i = 0 ;
            while( tmp != curr)
            {
                tmp = tmp->next;
                i++;
            }
            return i;
        }
        void next()const
        {
            if(curr->next!=nullptr)curr = curr->next;
        }

        void prev()const
        {
            if(curr == head)return;
            Link<E>* tmp = head;
            while(tmp -> next != curr)
            {
                tmp = tmp -> next;
            }
            curr = tmp;
        }

        int length()const{return cnt;}
        E getValue()const
        {
            assert(cnt!=0,"No value");
            return curr->next->element;
        }

        void append(E& it)
        {
            tail = tail -> next = new Link<E>(it,nullptr);
            cnt++;
        }

        void insert(E& it)
        {
            curr->next = new Link<E>(it,curr->next);
            if(tail == curr) tail = curr->next;
            cnt++;
        }

        E remove()
        {
            assert(cnt!=0,"No element in list");
            Link<E>* tmp = curr->next;
            E it = tmp->element;
            if(tail = curr->next)tail = curr;
            curr->next = tmp -> next;
            delete tmp;
            cnt--;
            return it;
        }
};