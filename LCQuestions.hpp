#ifndef LCQUESTIONS_HPP
#define LCQUESTIONS_HPP

#include "ListNode.hpp"

#include <string>
#include <vector>

class LCQuestions {

private:

public:

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
  void genParenHelper(std::vector<std::string> &vec, std::string str, int l, int r);


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

};

#endif
