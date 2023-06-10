#ifndef ARRAYSANDSTRINGS_HPP
#define ARRAYSANDSTRINGS_HPP

#include <string>
#include <vector>

class ArraysAndStrings {
private:
public:
  ArraysAndStrings() {}
  ~ArraysAndStrings() {}

  // std::cout << ar.isUnique("abcdefghijklmnopqrstuvwxyz")  << std::endl;
  bool isUnique(std::string str);

  // std::cout << ar.checkPermutation("fnnind", "frnind")    << std::endl;
  bool checkPermutation(std::string a, std::string b);

  // std::cout << ar.URLify("  Mr John Smith   ", 13)        << std::endl;
  std::string URLify(std::string str, int trueSize);

  // std::cout << ar.palindromePermutation("taioc cta")      << std::endl;
  bool palindromePermutation(std::string str);

  // std::cout << ar.oneAway("pale", "bake")                 << std::endl;
  bool oneAway(std::string a, std::string b);

  // std::cout << ar.stringCompression("aabbbccca")          << std::endl;
  // std::cout << ar.stringCompression("abcdefgashbidlg")    << std::endl;
  std::string stringCompression(std::string str);

  std::vector<std::vector<uint32_t>>
  rotateNinety(std::vector<std::vector<uint32_t>> matrix);
};

#endif
