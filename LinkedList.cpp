#include "LinkedList.hpp"


ListNode* LinkedList::getBack()
{
  if (m_size == 0) return nullptr;
  if (m_size == 1) return m_head;
    
  ListNode* temp = m_head;
  ListNode* next = temp->next;
  
  while (next) {
    temp = next;
    next = next->next;
  }
  return temp;
}

LinkedList::~LinkedList()
{
  ListNode* temp = m_head;
  while (m_head) {
    temp = m_head;
    m_head = m_head->next;
    delete temp;
  }
}

bool LinkedList::isEmpty()
{
  return (m_size == 0);
}

void LinkedList::addFront(ListNode* node)
{
  if (isEmpty()) {
    m_head = node;
  }
  else {
    node->next = m_head;
    m_head = node;
  }
  m_size++;
}

void LinkedList::addBack(ListNode* node)
{

  m_size++;
}

void LinkedList::removeFront(ListNode* node)
{
  
}

void LinkedList::removeBack(ListNode* node)
{

}
