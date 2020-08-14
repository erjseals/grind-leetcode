#include <iostream>
#include <vector>
#include <string>

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

// Function Declarations

// letterCominations returns a vector<string> that contains all possible 
// strings given a numerical combination. This is like t9 texting. 
// Example would be input "45" and returns "gj", "gk", "gl", "hj", "hk", "hl", "ij", "ik", "il" 
std::vector<std::string> letterCombinations(std::string digits);

// Given the head of a list, removes the nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n);

// Delete the entire list
ListNode* deleteList(ListNode* head);

// Given n pairs of parentheses, this function generates all combinations of well-formed parentheses.
std::vector<std::string> generateParenthesis(int n);

// Entry point
int main() 
{
    int input;

    std::cout << "Pairs of parentheses: ";
    std::cin >> input;

    std::vector<std::string> res = generateParenthesis(input);

    std::cout << "[" << std::endl;
    for(auto& a : res) {
        std::cout << "\t\"" << a << "\"" << std::endl;
    }
    std::cout << "]" << std::endl;
}

// Functions

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> res;

    

    return res;
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
    // Initialize the result vector with an empty string for the base case swap
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