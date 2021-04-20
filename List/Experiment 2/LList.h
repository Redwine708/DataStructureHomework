/*
 *We use three pointers to control the list and the curr pointer points the former
 *element than the curr position
 */ 
#ifndef _LLIST_
#define _LLIST_
#include<iostream>
#include "Link.h"
#include"assert.h"
#include "List.h"
using namespace std;
template<typename E>class LList : public List<E> 
{
    private:
        Link<E>* head;
        Link<E>* tail;
        Link<E>* curr;
        int cnt;

        void init()
        {
            curr = tail = head = new Link<E>;
            cnt = 0;
        }

        void removeall()
        {
            while(head != NULL)
            {
                curr = head;
                head = head -> next;
                delete curr;
            }
        }
    
    public:
        LList(int size = 100)
        {
            init();
        }
        ~LList(){removeall();}
        void clear(){removeall();init();}

        void insert(const E& it)
        {
            curr -> next = new Link<E>(it ,curr->next);
            if(tail == curr)tail = curr->next;
            cnt++;
        }

        void append(const E& it)
        {
            tail = tail -> next = new Link<E>(it , NULL);
            cnt++;
        }

        E remove()
        {
            Assert(curr->next != NULL , "No element");
            E it= curr -> next ->element;
            Link<E>* tmp = curr -> next;
            curr -> next = tmp -> next;
            if(tail == curr -> next) tail = curr;
            cnt --;
            delete tmp;
            return it;
        }

        void moveToStart()
        {
            curr = head;
        }

        void moveToEnd()
        {
            curr = tail;
        }

        void prev()
        {
            if( curr == head ) return ;
            Link<E>* tmp = head;
            while(tmp->next != curr)tmp = tmp -> next;
            curr = tmp;
        }

        void next()
        {
            Assert(curr != tail,"No next element");
            curr = curr -> next;
        }

        int length() const{
            return cnt;
        }

        int currPos()const{
            Link<E>* tmp = head;
            int i;
            for(i =  0; curr != tmp ; i++)
            {
                tmp = tmp -> next;
            }
            return i;
        }
        void moveToPos(int Pos)
        {
            Assert(Pos>=0 && Pos <=cnt , "Position out of range");
            curr = head;
            for(int i = 0; i < Pos ; i++)
            curr = curr -> next;
        }
        const E & getValue()const{
            Assert(curr->next != NULL,"No value");
            return curr->next->element;
        }
};


#endif