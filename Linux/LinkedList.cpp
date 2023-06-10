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
  if (m_head == nullptr) return nullptr;
  if (m_head->next == nullptr) return m_head;
    
  ListNode* temp = m_head;
  ListNode* next = temp->next;
  
  while (next) {
    temp = next;
    next = next->next;
  }
  return temp;
}

unsigned int LinkedList::getSize()
{
  unsigned int ret = 0;
  ListNode* runner = m_head;

  while (runner) {
    ret++; 
    runner = runner->next;
  }

  return ret;
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
  return (m_head == nullptr);
}

void LinkedList::removeDups()
{
  if (m_head == nullptr) return;
  if (m_head->next == nullptr) return;

  std::unordered_set<int> set;

  ListNode* it = m_head;
  set.insert(it->val);

  while (it->next) {

    // Search if already in set
    auto search = set.find(it->next->val);
    if (search != set.end()) {
      ListNode* temp = it->next->next;
      delete it->next;
      it->next = temp;
    }
    else 
      set.insert(it->next->val);

    // Don't move iterator if at the end
    if (it->next)
      it = it->next;
  }
}

void LinkedList::removeDupsInPlace()
{
  if (m_head == nullptr) return;
  if (m_head->next == nullptr) return;

  ListNode* slow = m_head;
  ListNode* fast = m_head;

  while (slow) {
    while (fast->next) {
      if (slow->val == fast->next->val) {
        // Delete Node pointed to by fast
        // Is it in the middle or at the end?
        if (fast->next->next) {
          ListNode* temp = fast->next->next;
          delete fast->next;
          fast->next = temp;
        }
        else {
          delete fast->next;
          fast->next = nullptr;
        }
      }
      else {
        fast = fast->next;
      }
    } 
    // Increment, doesn't do anything on the last case
    if (slow->next) {
      slow = slow->next;
      fast = slow;
    }
    else
      slow = nullptr;
  }
}

// k = 1 returns the last element
ListNode* LinkedList::findKthToLast(unsigned int k) 
{
  // Need to go through the list, and then backwards to the specific node
  unsigned int size = getSize();
  
  // If k is out of bounds, 
  if (k > size ) return nullptr;

  ListNode* runner = m_head;

  for (unsigned int i = 0 ; i < size-k ; i++) {
    runner = runner->next;
  }
  return runner;
}

ListNode* LinkedList::findKthToLastOptimally(unsigned int k)
{
  // Use two pointers, seperted k elements
  ListNode* p1 = m_head;
  ListNode* p2 = m_head;

  for (unsigned int i = 0 ; i < k ; i++) {
    if (p2) 
      p2 = p2->next;
    else
      return nullptr;
  }

  while (p2) {
    p2 = p2->next;
    p1 = p1->next;
  }

  return p1;
}

unsigned int LinkedList::detectLoop(ListNode** ret)
{
  *ret = nullptr;
  if (m_head == nullptr) return -1;
  if (m_head->next == nullptr) return -1;
  if (m_head->next->next == nullptr) return -1;

  ListNode* fast = m_head->next->next;
  ListNode* slow = m_head->next;

  while (fast != slow) {
    // Do bound checks for the fast ptr
    // If ever it hits a nullptr, there is not a cycle
    if (fast->next == nullptr) return -1;
    fast = fast->next;
    
    if (fast->next == nullptr) return -1;
    fast = fast->next;
    
    slow = slow->next;
  }

  unsigned int count = 0;
  slow = m_head;

  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
    count++;
  }

  *ret = slow;
  return count;
}

void LinkedList::removeLoop(ListNode* loopStart)
{
  ListNode* temp = m_head;
  
  if (temp == nullptr) return;  

  // First pass
  while (temp->next != loopStart) {
    temp = temp->next;
  }

  temp = temp->next;

  // Second pass
  while (temp->next != loopStart) {
    temp = temp->next;
  }
  
  temp->next = nullptr;
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

void LinkedList::printKTimes(unsigned int k) 
{
  ListNode* temp = m_head;
  while (temp && k > 0) {
    std::cout << temp->val << ' ';
    temp = temp->next;
    k--;
  }
  std::cout << std::endl;
}










