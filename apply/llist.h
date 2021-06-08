#include"link.h"
#include"list.h"
#include "list.h"
#include<assert.h>

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation
using namespace std;
template <typename E> class LList: public List<E> {
private:
  Link<E>* head;       // ָ������ͷ��� 
  Link<E>* tail;       // ָ���������һ����� 
  Link<E>* curr;       // ָ��ǰԪ�� 
  int cnt;    	       // ��ǰ�б���С 

  void init() {        // ��ʼ��
    curr = tail = head = new Link<E>;
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store 
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  LList(int size=100) { init(); }    // ���캯�� 
  ~LList() { removeall(); }                   // ��������
  void print() const;                // ��ӡ�б�����
  void clear() { removeall(); init(); }       // ����б�

  // �ڵ�ǰλ�ò��롰it��
  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);  
    if (tail == curr) tail = curr->next;  //�µ�βָ�� 
    cnt++;
  }

  void append(const E& it) { // ׷�ӡ�it�����б���
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
  }

  // ɾ�������ص�ǰԪ��
  E remove() {
    assert(curr->next != NULL);//"No element"
    E it = curr->next->element;      // ����Ԫ��ֵ
    Link<E>* ltemp = curr->next;     // ����ָ������Ϣ 
    if (tail == curr->next) tail = curr; // ����βָ��
    curr->next = curr->next->next;   // ���б���ɾ�� 
    delete ltemp;                    //���տռ�
    cnt--;			     // ��ǰ�б���С��һ
    return it;
  }

  void moveToStart() // ��curr�������б�ͷ��
    { curr = head; }

  void moveToEnd()   // ��curr�������б�β��
    { curr = tail; }

  // ��currָ����ǰ������һ��������Ѿ�ָ��ͷ���˾Ͳ���Ҫ�ı� 
  void prev() {
    if (curr == head) return;       // ֮ǰû��Ԫ�� 
    Link<E>* temp = head;
    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // ��currָ�������ң���һ��������Ѿ�ָ��β���˾Ͳ���Ҫ�ı� 
  void next()
    { if (curr != tail) curr = curr->next; }

  int length() const  { return cnt; } // ���ص�ǰ�б���С

  // ���ص�ǰԪ�ص�λ��
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // �����ƶ����б���pos��λ��
  void moveToPos(int pos) {
    assert ((pos>=0)&&(pos<=cnt));//"Position out of range"
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // ���ص�ǰԪ��
    assert(curr->next != NULL);//"No value"
    return curr->next->element;
  }
};
