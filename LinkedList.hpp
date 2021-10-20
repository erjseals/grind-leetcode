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

  void removeDups();

  void addFront(ListNode* node);
  void addBack(ListNode* node);
  bool removeFront();
  bool removeBack();

  void print();

};

#endif
