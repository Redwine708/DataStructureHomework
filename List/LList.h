#ifndef _LLIST_
#define _LLIST_
#include "Link.h"
#include "List.h"
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
template<typename E>class LList: public Link<E>,public List<E>
{
    private:
        static Link<E>* head;
        static Link<E>* curr;
        static Link<E>* tail;
        int cnt;

        void init()
        {
            head = curr = tail = NULL;
            cnt = 0;
        }

        void removeall()
        {
            while(head!=NULL)
            {
                curr = head;
                head = head ->next;
                delete curr;
            }
        }
    
    public:
        LList(){init();}
        LList(string s)
        {
            init();
            Link<E>* tmp = head ;
            for(int i = 0 ; i < s.size() ; i++)
            {
                insert(s[i]);  //insert
            }
        }
        friend ostream& operator << (ostream &output , LList const& t)
        {
            Link<E>* tmp = head;
            while(tmp ->next != NULL)
            {
                output<<tmp->next->element;
            }
            return output;

        }
        ~LList(){removeall();}
        void clear(){removeall();init();}
        void removeDigit()
        {
            moveToStart();
            if(isdigit(curr->element))remove();
        }
        E remove()
        {
            E it = curr -> next ->element;
            Link<E>* tmp = curr ->next;
            curr->next = tmp -> next;
            if(curr->next == tail) tail = curr;
            cnt --;
            delete tmp;
            return it;
        }
        int calAlpha()
        {
            int count = 0;
            Link<E>* tmp = head;
            for(;tmp!=tail; tmp = tmp-> next)
            {
                if(isalpha(tmp->element))count++;
            }
            return count;
        }
        int calDigit()
        {
            int count = 0;
            Link<E>* tmp = head;
            for(;tmp!=tail; tmp = tmp-> next)
            {
                if(isdigit(tmp->element))count++;
            }
            return count;
        }
        void moveToStart()
        {
            curr = head;
        }
        void insert(const E& it)
        {
            curr->next = new Link<E>(it , curr -> next);
            if(tail == curr) tail = curr->next;
            cnt++;
        }

        int getCnt()const{
            return cnt;
        }


};

#endif