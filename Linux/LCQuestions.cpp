#include "LCQuestions.hpp"

#include "ListNode.hpp"
#include "PriorityQueue.hpp"

/* Functions */

std::vector<std::string> LCQuestions::letterCombinations(std::string digits) 
{
  std::vector<std::string> t9 = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  
  // Initialize the result std::vector with an empty std::string for the base case swap
  std::vector<std::string> res = {""};

  for(unsigned int i = 0 ; i < digits.size() ; i++) 
  {
    // Digits need to range between 0 and 9.
    // For example, the ascii value for 3 is 51 and 0 is 48. 51 - 48 is 3.  
    int digit = digits[i] - '0';

    // Only digits 2 to 9 are valid, but I handle 0 and 1 incase user hits those numbers
    if(0 > digit || digit > 9) continue;

    // Use a const ref since we won't change the values.
    const std::string& str = t9[digit]; 

    std::vector<std::string> temp;

    for(unsigned int k = 0 ; k < res.size() ; k++) 
      for(unsigned int j = 0 ; j < str.size() ; j++) 
        temp.push_back(res[k] + str[j]);

    res.swap(temp);
  }
  return res;
}



ListNode* LCQuestions::removeNthFromEnd(ListNode* head, int n) 
{
  if(!head) return head;

  ListNode* checkIfNth = head;
  for(int i = 0 ; i < n ; i++) 
  {
    if(!checkIfNth) return checkIfNth;
      checkIfNth = checkIfNth->next;
  }

  // If this is nullptr at this point in function,
  // then it is the nth node to remove
  if(!checkIfNth) 
  {
    ListNode* next = head->next;
    delete head;
    head = nullptr;
    return next;
  }
  head->next = removeNthFromEnd(head->next, n);
  return head;
}



ListNode* LCQuestions::deleteList(ListNode* head) 
{
  while(head) 
  {
    ListNode* next = head->next;
    delete head;
    head = next;    
  }
  return head;
}



std::vector<std::string> LCQuestions::generateParenthesis(int n)
{
  std::vector<std::string> vec;
  genParenHelper(vec, "", n, 0);
  return vec;
}



void LCQuestions::genParenHelper(std::vector<std::string> &vec, std::string str, int l, int r) 
{
  if(l == 0 && r == 0) 
  {
    vec.push_back(str);
    return;
  }
    
  if(l > 0) 
    genParenHelper(vec, str+"(", l - 1, r + 1);
  if(r > 0) 
    genParenHelper(vec, str+")", l, r - 1);
}



// Returns the index of the start of the cycle 
int LCQuestions::getStartOfCycle(ListNode* ln)
{
  // Make sure there is a cycle
  if(!isCycle(ln)) return 0;

  ListNode * slowPtr = ln;
  ListNode * fastPtr = ln;

  while(fastPtr)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr)
      break;
  }

  fastPtr = ln;
  int count = 0;

  while(fastPtr)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;

    count++;

    if(slowPtr == fastPtr)
      break;
  }
  return count;
}



ListNode* LCQuestions::mergeKLists(std::vector<ListNode*>& lists) 
{
  if(lists.size() < 1) return nullptr;

  else if(lists.size() < 2) return lists[0];

  else 
  {
    // Set initial values, then loop through the rest
    ListNode* ret = mergeTwoLists(lists[0], lists[1]);
        
    for(unsigned int i = 2 ; i < lists.size() ; i++) 
      ret = mergeTwoLists(ret, lists[i]);        
        
    return ret;
  }
}



ListNode* LCQuestions::mergeKListsPQ(std::vector<ListNode*>& lists)
{
  PriorityQueue pq;

  ListNode* temp;
  // Throw everything into the priority queue
  for(auto & list : lists)
  {
    temp = list;
    while(temp)
    {
      pq.push(temp);
      temp = temp->next;
    }
  }

  // temp = new ListNode(1);

  ListNode* head = pq.pop();

  if(!head) return nullptr;

  temp = head;

  while(!pq.empty())
  {
    temp->next = pq.pop();
    temp = temp->next;
  }
    
  temp->next = nullptr;

  return head;
}



ListNode* LCQuestions::mergeTwoLists(ListNode* l1, ListNode* l2)
{
  if(!l1) return l2;
  else if(!l2) return l1;

  if(l1->val <= l2->val) 
  {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }
  else 
  {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}



bool LCQuestions::isCycle(ListNode* ln)
{
  ListNode * slowPtr = ln;
  ListNode * fastPtr = ln;

  while(fastPtr)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr)
    {
      return true;
    }
  }
  return false;
}
