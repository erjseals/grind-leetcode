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

  // Double pointers are ugly, but I wanted to remember
  unsigned int detectLoop(ListNode** ret);

  // Pass the returned value of detectLoop
  void removeLoop(ListNode* loopStart);

  void addFront(ListNode* node);
  void addBack(ListNode* node);
  bool removeFront();
  bool removeBack();

  void print();
  void printKTimes(unsigned int k);

};

#endif
