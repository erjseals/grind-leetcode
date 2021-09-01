#ifndef ARRAYSANDSTRINGS_HPP
#define ARRAYSANDSTRINGS_HPP

#include <string>

class ArraysAndStrings 
{
private:

public:
  ArraysAndStrings(){}
  ~ArraysAndStrings(){}

  bool isUnique(std::string str);
  bool checkPermutation(std::string a, std::string b);
  std::string URLify(std::string str, int trueSize);
  bool palindromePermutation(std::string str);
};


#endif
