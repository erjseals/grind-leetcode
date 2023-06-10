#include <iostream>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "ListNode.hpp"
#include "PriorityQueue.hpp"
#include "Stack.hpp"
// #include "StackWithMin.hpp"
#include "ArraysAndStrings.hpp"
#include "LCQuestions.hpp"
#include "LinkedList.hpp"

/*******************************************************************************************************/

/* Entry point */

int main() {
  Stack s;

  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  ListNode *node6 = new ListNode(6);
  ListNode *node7 = new ListNode(7);

  LinkedList *ll = new LinkedList();
  ll->addBack(node1);
  ll->addBack(node2);
  ll->addBack(node3);
  ll->addBack(node4);
  ll->addBack(node5);
  ll->addBack(node6);
  ll->addBack(node7);

  // Deliberately create a loop
  // node7->next = node3;

  ll->printKTimes(20);

  ListNode *node = nullptr;
  ll->detectLoop(&node);

  if (node)
    ll->removeLoop(node);

  ll->printKTimes(20);

  delete ll;
}

/*******************************************************************************************************/
