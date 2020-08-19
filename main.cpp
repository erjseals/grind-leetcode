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
    ListNode* head;
    int m_size;
public:
    PriorityQueue() : head(nullptr), m_size(0){}
    
    ~PriorityQueue(){}
    
    bool empty()
    {
        return m_size == 0 ? true : false;
    }    
    
    int size()
    {
        return m_size;
    }
    
    void push(ListNode* ln);
    ListNode* pop();
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

    ListNode* l13 = new ListNode(5);
    ListNode* l12 = new ListNode(4, l13);
    ListNode* l11 = new ListNode(1, l12);

    ListNode* l23 = new ListNode(4);
    ListNode* l22 = new ListNode(3, l23);
    ListNode* l21 = new ListNode(1, l22);

    ListNode* l32 = new ListNode(6);
    ListNode* l31 = new ListNode(2, l32);

    lists.push_back(l11);
    lists.push_back(l21);
    lists.push_back(l31);

    ListNode* head = mergeKLists(lists);

    std::cout << "[";

    while(head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }

    std::cout << "]" << std::endl;

    delete l13;
    delete l12;
    delete l11;

    delete l23;
    delete l22;
    delete l21;

    delete l32;
    delete l31;
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