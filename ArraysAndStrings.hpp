#ifndef ARRAYSANDSTRINGS_HPP
#define ARRAYSANDSTRINGS_HPP

#include <string>
#include <vector>

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
  bool oneAway(std::string a, std::string b);
  std::string stringCompression(std::string str);
  std::vector<std::vector<uint32_t>> rotateNinety(std::vector<std::vector<uint32_t>> matrix);
};


#endif
