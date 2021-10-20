#include "LinkedList.hpp"

#include <iostream>
#include <unordered_set>

std::ostream& operator<< (std::ostream& os, std::unordered_set<int> const& s) {
  for (os << "[" << s.size() << "] { "; int i : s)
    os << i << ' ';
  return os << "}\n";
}

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

void LinkedList::removeDups()
{
  if (m_size == 0) return;
  if (m_size == 1) return;

  std::unordered_set<int> set;

  ListNode* it = m_head;
  set.insert(it->val);

  while (it->next) {

    // Search if already in set
    auto search = set.find(it->next->val);
    if (search != set.end()) {
      ListNode* temp = it->next->next;
      delete it->next;
      m_size--;
      it->next = temp;
    }
    else 
      set.insert(it->next->val);

    // Don't move iterator if at the end
    if (it->next)
      it = it->next;
  }
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
  if (isEmpty()) {
    m_head = node;
  }
  else {
    ListNode* temp = getBack();
    temp->next = node;
  }
  m_size++;
}

bool LinkedList::removeFront()
{
  if (isEmpty()) {
    return false;
  } 
  else {
    ListNode* temp = m_head->next;
    delete m_head;
    m_head = temp;
    m_size--;
    return true;
  }
}

bool LinkedList::removeBack()
{
  if (isEmpty()) {
    return false;
  } 
  else if (m_head->next == nullptr) {
    delete m_head;
    m_head = nullptr;
    m_size = 0;
    return true;
  }
  else {
    ListNode* first  = m_head;
    ListNode* second = m_head->next;

    while (second->next) {
      first  = second;
      second = second->next;
    }

    delete second;
    first->next = nullptr;
    m_size--;
    return true;
  }
}

void LinkedList::print() 
{
  ListNode* temp = m_head;
  while (temp) {
    std::cout << temp->val << ' ';
    temp = temp->next;
  }
  std::cout << std::endl;
}













