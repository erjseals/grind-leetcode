#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    // Given a string s, find the length of the longest substring without repeating characters.
    int lengthOfLongestSubstring(std::string s) {
      if(s.length() <= 1) return 0;
      if(s.length() == 1) return 1;
      int max = 0;
      std::unordered_set<char> us;
      for(size_t i = 0 ; i < s.length() ; i += 1) {
        us.clear();
        for(size_t j = i ; j < s.length() ; j+=1) {
          auto it = us.find(s.at(j));
          if(it != us.end()) {
            break;
          }
          else {
            us.insert(s.at(j));
            if( max < static_cast<int>(us.size())) {
              max = static_cast<int>(us.size());
            }
          }
        }
      }
      return max;
    }

    void test(){
      int res = 0;

      std::string s1 = "abcabcbb";
      res = lengthOfLongestSubstring(s1);
      if( res == 3) {
        std::cout << "Test 1: pass" << std::endl;
      }
      else {
        std::cout << "Test 1: failed: expected 3, actual " << res  << std::endl;
      }

      std::string s2 = "bbbbb";
      res = lengthOfLongestSubstring(s2);
      if(res == 1) {
        std::cout << "Test 2: pass" << std::endl;
      }
      else {
        std::cout << "Test 2: failed: expected 1, actual " << res  << std::endl;
      }

      std::string s3 = "pwwkew";
      res = lengthOfLongestSubstring(s3);
      if( res == 3) {
        std::cout << "Test 3: pass" << std::endl;
      }
      else {
        std::cout << "Test 3: failed: expected 3, actual " << res  << std::endl;
      }
    }
};

/* Entry point */

int main() {
  Solution soln;
  soln.test();
}

