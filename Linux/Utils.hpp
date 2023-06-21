#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

class Utils {
  public:
    void test();

    int lengthOfLongestSubstring(std::string s);
    int minSubArrayLen(int target, std::vector<int>& nums);
};

#endif
