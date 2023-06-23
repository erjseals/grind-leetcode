#ifndef SW_HPP
#define SW_HPP

#include <string>
#include <vector>

namespace SW {
    void test();

    int lengthOfLongestSubstring(std::string s);
    int minSubArrayLen(int target, std::vector<int>& nums);
    int characterReplacement(std::string s, int k);
};

#endif
