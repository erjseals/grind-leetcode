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
#include "LLUtility.hpp"
#include "LinkedList.hpp"
#include "LCQuestions.hpp"

/*******************************************************************************************************/

/* Entry point */

int main() 
{   
  {
    LinkedList ll; 

    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);

    ll.addFront(node1);
    ll.addFront(node2);
    ll.addFront(node3);
    ll.addFront(node4);
    ll.addFront(node5);

    ll.print();

    ll.removeFront();
    ll.removeFront();
    ll.removeFront();
    ll.removeFront();
    ll.removeFront();

    ll.print();
  }

  {
    LinkedList ll; 

    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);

    ll.addBack(node1);
    ll.addBack(node2);
    ll.addBack(node3);
    ll.addBack(node4);
    ll.addBack(node5);

    ll.print();
    
    ll.removeBack();
    ll.removeBack();
    ll.removeBack();
    ll.removeBack();
    ll.removeBack();

    ll.print();
  }
}


/*******************************************************************************************************/

