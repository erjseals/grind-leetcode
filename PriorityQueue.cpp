#include <iostream>
#include <string>
#include <vector>

#include "PriorityQueue.hpp"

void PriorityQueue::percolateUp(int index) 
{
  if (index < 1)
    return;
  // Compare the node to its parent
  if (compare(m_container[ index ], m_container[ (index - 1) / 2 ]))
  {
    ListNode* swap = m_container[ (index - 1) / 2 ];
    m_container[ (index - 1) / 2 ] = m_container[ index ];
    m_container[ index ] = swap;
    percolateUp( (index - 1) / 2 );
  }
  return;
}

void PriorityQueue::percolateDown(int index)
{
  // Check if and then which child to swap with
  // First see if there even exists children

  int lChild = index * 2 + 1;
  int rChild = index * 2 + 2;

  // Case 1 : no children
  if ( lChild > (m_size - 1) )
    return;

  // Case 2 : Only left child
  if ( lChild == (m_size - 1) )
  {
    // Left child has higher priority than parent
    if (compare( m_container[ lChild ], m_container[index]))
    {
      ListNode* swap = m_container[ index ];
      m_container[ index ] = m_container[ lChild ];
      m_container[ lChild ] = swap;
    }
    // No need to percolate down
    return;
  }

  // Case 3 : Two children 
  // First assess which of the two has higher priority

  // This evaluates true when left has higher priority
  if ( compare(m_container[lChild], m_container[rChild]) )
  {
    // Left child has higher priority than parent
    if (compare( m_container[ lChild ], m_container[index]))
    {
      ListNode* swap = m_container[ index ];
      m_container[ index ] = m_container[ lChild ];
      m_container[ lChild ] = swap;
      percolateDown(lChild);
    }
    return;
  }
  else 
  {
    // Right child has higher priority than parent
    if (compare( m_container[ rChild ], m_container[index]))
    {
      ListNode* swap = m_container[ index ];
      m_container[ index ] = m_container[ rChild ];
      m_container[ rChild ] = swap;
      percolateDown(rChild);
    }
    return;
  }
}


bool PriorityQueue::compare(ListNode* a, ListNode* b) 
{
  if(a->val < b->val)
    return true;
  else 
    return false; 
}

// Puts new node into the tree
// then calls a function to do necessary percolations
void PriorityQueue::push(ListNode* ln)
{
  std::cout << "What is being pushed?" << ln->val << std::endl;

  // Case 1 : Empty
  if(m_size == 0)
  {
    m_container.push_back(ln);
    m_size++;
  }

  // Case 2 : Non-Empty
  // Put the new element into the vector. The index will be m_size
  else 
  {
    m_container.push_back(ln);
    percolateUp(m_size);
    m_size++;
  }
}

ListNode* PriorityQueue::pop()
{
  if(empty())
  {
    std::cout << "Popping empty!" << std::endl;
    return nullptr;
  }

  // Grab the top node to return in a moment
  ListNode* ret = m_container[0];

  // Decrement the size of Queue
  m_size--;

  if(m_size > 0)
  {
    // Set the top of the Queue to the very bottom right most Node 
    m_container[0] = m_container[m_size];

    // Percolate down starting at index 0
    percolateDown(0);
  }

  std::cout << "What is being popped?" << ret->val << std::endl;

  // Pop that element from the container
  m_container.pop_back();

  // return the node
  return ret;
}
