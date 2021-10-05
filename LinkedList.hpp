#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "ListNode.hpp"

class LinkedList
{
private:
  ListNode* m_head;
  unsigned int m_size;

  ListNode* getBack();

public:
  LinkedList()
  : m_head(nullptr), m_size(0){}
  ~LinkedList();

  bool isEmpty();

  void addFront(ListNode* node);
  void addBack(ListNode* node);
  void removeFront(ListNode* node);
  void removeBack(ListNode* node);

};

#endif
