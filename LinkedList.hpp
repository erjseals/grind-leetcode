#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "ListNode.hpp"

class LinkedList
{
private:
  ListNode* m_head;

  ListNode* getBack();
  unsigned int getSize();
  
public:
  LinkedList()
  : m_head(nullptr){}
  ~LinkedList();

  bool isEmpty();

  void removeDups();
  void removeDupsInPlace();

  ListNode* findKthToLast(unsigned int k);
  ListNode* findKthToLastOptimally(unsigned int k);

  void addFront(ListNode* node);
  void addBack(ListNode* node);
  bool removeFront();
  bool removeBack();

  void print();

};

#endif
