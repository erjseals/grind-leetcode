#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "ListNode.hpp"

class PriorityQueue
{
private:
  int m_size;
  std::vector<ListNode*> m_container;

  // Given the index of the newly inserted node
  // percolate this node up the tree as needed
  // 
  void percolateUp (int index);

  void percolateDown (int index); 

  bool compare(ListNode* a, ListNode* b);

public:
  PriorityQueue() 
  : m_size(0){}
    
  ~PriorityQueue(){}
    
  bool empty()
  {
    return m_size < 1;
  }    
    
  int size()
  {
    return m_size;
  }

  ListNode* top() 
  {
    if(empty()) 
      return nullptr;
    else 
      return m_container[0];
  }

  void push(ListNode* ln);

  ListNode* pop();
};

#endif
