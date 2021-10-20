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
#include "ArraysAndStrings.hpp"
#include "LinkedList.hpp"
#include "LCQuestions.hpp"

/*******************************************************************************************************/

/* Entry point */

int main() 
{   
  ListNode * node1 = new ListNode(1);
  ListNode * node2 = new ListNode(2);
  ListNode * node3 = new ListNode(3);
  ListNode * node4 = new ListNode(4);
  ListNode * node5 = new ListNode(5);
  ListNode * node6 = new ListNode(3);

  LinkedList* ll = new LinkedList();
  ll->addBack(node1);
  ll->addBack(node2);
  ll->addBack(node3);
  ll->addBack(node4);
  ll->addBack(node5);
  ll->addBack(node6);

  ll->removeDups();

  ll->print();

  delete ll;
}


/*******************************************************************************************************/

