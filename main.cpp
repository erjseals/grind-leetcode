#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>

// I wouldn't normally do this
// But Leetcode does, so that's what I'm practicing

// Data Structures and Constants Necessary
std::vector<std::string> t9 = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

struct ListNode 
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class PriorityQueue
{
private:
  int m_size;
  std::vector<ListNode*> m_container;

  // Given the index of the newly inserted node
  // percolate this node up the tree as needed
  // 
  void percolateUp (int index) 
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

  void percolateDown (int index) 
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

  bool compare(ListNode* a, ListNode* b) 
  {
    if(a->val < b->val)
      return true;
    else 
      return false; 
  }

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

  // Puts new node into the tree
  // then calls a function to do necessary percolations
  void push(ListNode* ln)
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

  ListNode* pop()
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
};

class Node
{
public:

private:
};



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

// Entry point
int main() 
{   
  std::vector<ListNode*> lists;

  ListNode* l14 = new ListNode(-1);
  ListNode* l13 = new ListNode(-1, l14);
  ListNode* l12 = new ListNode(-1, l13);
  ListNode* l11 = new ListNode(-2, l12);

  ListNode* l21 = nullptr;

  lists.push_back(l11);
  lists.push_back(l21);

  ListNode* head = mergeKListsPQ(lists);

  std::cout << "[";

  while(head)
  {
    int input;
    std::cin >> input;
    std::cout << head->val << " ";
    head = head->next;
  }

  std::cout << "]" << std::endl;

  delete l14;
  delete l13;
  delete l12;
  delete l11;
}

// Functions

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
