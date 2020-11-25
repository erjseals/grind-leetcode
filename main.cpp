#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <set>

#include "ListNode.hpp"
#include "PriorityQueue.hpp"
#include "Stack.hpp"

// I wouldn't normally do this
// But Leetcode does, so that's what I'm practicing

// Data Structures and Constants Necessary
std::vector<std::string> t9 = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Function Declarations

// letterCominations returns a std::vector<std::string> that contains all possible 
// std::strings given a numerical combination. This is like t9 texting. 
// Example would be input "45" and returns "gj", "gk", "gl", "hj", "hk", "hl", "ij", "ik", "il" 
std::vector<std::string> letterCombinations(std::string digits);

// Given the head of a list, removes the nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n);

// Delete the entire list
ListNode* deleteList(ListNode* head);

// Given n pairs of parentheses, this function generates all combinations of well-formed parentheses.
std::vector<std::string> generateParenthesis(int n);

// Helper for generateParenthesis
void helper(std::vector<std::string> &vec, std::string str, int l, int r);

// Merge k lists into one.
ListNode* mergeKLists(std::vector<ListNode*>& lists);

// Merge k lists using std library priority queue
ListNode* mergeKListsPQ(std::vector<ListNode*>& lists);

// Merge two lists into one
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

// Returns true if there is a cycle in the list
bool isCycle(ListNode* ln);

// Returns the index of the start of the cycle 
int getStartOfCycle(ListNode* ln);

int solution(std::vector<int> A);

std::vector<int> toIntVector(std::string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}


// Entry point
int main() 
{   
  std::vector<int> A = toIntVector("5,4,3,6,1");
  std::cout << solution(A);
}

int solution(std::vector<int> A)
{
  int ret_rows = 0;
  // Every element in the row needs to be greater than A[i]
  
  // Use a std::set
  // This allows us to access the min / max / and current element in constant time
  
  // Create a vector of the row, each row is a std::set
  std::vector<std::set<int>> vec;
  
  
  for(size_t i = 0 ; i < A.size() ; i++)
  {
    // Init, create a new row
    if(i == 0)
    {
      std::set<int> tmp;
      tmp.insert(A[i]);
      vec.push_back(tmp);
    }
    else
    {
      // Loop through the rows.
      
      bool rowFound = false;
      for(size_t i = 0 ; i < vec.size() ; i++)
      {
        // Check the beginning
        // Get the minimum element 
        int min_element; 
        if (!vec[i].empty()) 
          min_element = *vec[i].begin(); 
  
        // Min element in the row is not greater, move on
        if(!(min_element > A[i])) continue;
        
        // See if the value is in the row
        // So, if this returns > 0 move to the next row
        if(vec[i].count(A[i])) continue;
        
        // If here, add the new student to this row
        vec[i].insert(A[i]);
      }
      
      // A sufficient row NOT found, add a new one
      if(!rowFound)
      {
        std::set<int> newRow;
        newRow.insert(A[i]);
        vec.push_back(newRow);
      }
    }
  }
  
  // Your solution goes here.
  return vec.size(); 
}


// Functions

bool isCycle(ListNode* ln)
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

// Returns the index of the start of the cycle 
int getStartOfCycle(ListNode* ln)
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
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

ListNode* mergeKLists(std::vector<ListNode*>& lists) 
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

ListNode* mergeKListsPQ(std::vector<ListNode*>& lists)
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

std::vector<std::string> generateParenthesis(int n)
{
  std::vector<std::string> vec;
  helper(vec, "", n, 0);
  return vec;
}

void helper(std::vector<std::string> &vec, std::string str, int l, int r) 
{
  if(l == 0 && r == 0) 
  {
    vec.push_back(str);
    return;
  }
    
  if(l > 0) 
    helper(vec, str+"(", l - 1, r + 1);
  if(r > 0) 
    helper(vec, str+")", l, r - 1);
}

ListNode* deleteList(ListNode* head) 
{
  while(head) 
  {
    ListNode* next = head->next;
    delete head;
    head = next;    
  }
  return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
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

std::vector<std::string> letterCombinations(std::string digits) 
{
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
