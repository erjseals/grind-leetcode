#include "ArraysAndStrings.hpp"
#include <unordered_set>
#include <unordered_map>

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
