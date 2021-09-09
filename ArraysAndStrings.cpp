#include "ArraysAndStrings.hpp"
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

bool ArraysAndStrings::isUnique(std::string str)
{
  std::unordered_set<char> set;


  set.insert(str[0]);

  for (size_t i = 1 ; i < str.size() ; i++)
  {
    auto search = set.find(str[i]);

    // If not set.end(), already exists... not unique
    if (search != set.end()) {
      return false;
    }
    else {
      set.insert(str[i]);
    }
  }

  return true;
}



// If string b is a permutation of string a, vice-versa
bool ArraysAndStrings::checkPermutation(std::string a, std::string b)
{
  if (a.size() != b.size()) return false;

  std::unordered_map<char, int> set;

  for (size_t i = 0 ; i < a.size() ; i++) 
  {
    auto search = set.find(a[i]);
    
    if (search != set.end())
      set[a[i]]++;
    else
      set[a[i]] = 1;
  }

  for (size_t i = 0 ; i < b.size() ; i++) 
  {
    auto search = set.find(b[i]);

    if (search != set.end())
    {
      if (set[b[i]] > 0) set[b[i]]--;
      else return false;
    }
    else return false;
  }

  return true;
}



std::string ArraysAndStrings::URLify(std::string str, int trueSize)
{
  std::vector<std::string> sv;
  bool newWord = true;
  int index = 0;

  // Fill vector with words
  for (size_t i = 0 ; i < str.size() ; i++) {
    if (str[i] == ' ') {
      if (!newWord) {
        newWord = true;
        index++;
      }
    }
    else {
      if (newWord) {
        sv.push_back("");
        sv[index] += str[i];
        newWord = false;
      }
      else
        sv[index] += str[i];
    }
  }
  
  // Rebuild in the str
  int j = 0;
  size_t size = sv.size();
  for (size_t i = 0 ; i < (size - 1) ; i++) {
    for (size_t k = 0 ; k < sv[i].size() ; k++) {
      str[j++] = sv[i][k];
    }
    str[j++] = '%';
    str[j++] = '2';
    str[j++] = '0';
  }
  for (size_t k = 0 ; k < sv[size-1].size() ; k++) {
    str[j++] = sv[size-1][k];
  }

  return str;
}



// This just needs to find a palindrome
// And we ignore the spaces
//
// Palindrome has all pairs of letters, but there can be ONE non-pair
bool ArraysAndStrings::palindromePermutation(std::string str)
{
  std::unordered_map<char, int> ht;
  
  for (size_t i = 0 ; i < str.size() ; i++) {
    if (str[i] == ' ');
    else {
      auto search = ht.find(str[i]);
      
      if (search != ht.end())
        ht[str[i]]++;
      else
        ht[str[i]] = 1;
    }
  }

  bool foundOdd = false;

  for (auto it : ht) {
    if (it.second % 2 != 0) {
      if (foundOdd) return false;
      else foundOdd = true;
    } 
  }

  return true;
}



// Check if two strings are one edit (or zero) away from eachother
bool ArraysAndStrings::oneAway(std::string a, std::string b)
{
  bool oneError = false;
  if (a.size() == b.size()) {
    for (size_t i = 0 ; i < a.size() ; i++) {
      if (a[i] == b[i]);
      else {
        if (oneError) return false;
        else oneError = true;
      }
    }
  }
  else if (abs(a.size() - b.size()) == 1) {
    bool aLarger = true;
    size_t size = 0;

    if (a.size() > b.size())
      size = a.size();
    else {
      aLarger = false;
      size = b.size();
    }

    size_t j = 0;
    for (size_t i = 0 ; i < size ; i++) {
      if ( (aLarger && a[i] == b[j]) || (!aLarger && a[j] == b[i] ))
        j++;
      else {
        if (oneError) return false;
        else oneError = true;
      }
    }
  }
  else
    return false;
  
  return true;
}


/*
 * Method to perform basic string compression using the counts
 * of repeated characters. For example, the string aabcccccaaa
 * would become a2b1c5a3. If the "compressed" string would not
 * become smaller than the original string, your method should
 * return the original string. You can assume the string has
 * only uppercase and lowercase letters (a-z).
*/
std::string ArraysAndStrings::stringCompression(std::string str)
{
  std::string ret;
  bool checkComp = false;
  for (size_t i = 0 ; i < str.size() ;) {
    char currChar = str[i]; 
    int count = 0;
    while (str[i] == currChar) {
      i++;
      count++;
    }
    ret.push_back(currChar);
    std::string temp = std::to_string(count);
    ret += temp;

    if (count > 1) checkComp = true;
  } 
  if (!checkComp) return str;
  else return ret;
}



/*
 * Each individual element comprises of a 32bit pixel
 * Right now, we will do a clockwise 90 rotation
*/
std::vector<std::vector<uint32_t>> 
ArraysAndStrings::rotateNinety(std::vector<std::vector<uint32_t>> matrix)
{
  

  return matrix;
}











