#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    // Given a string s, find the length of the longest substring without repeating characters.
    int lengthOfLongestSubstring(std::string s) {
      int ret = 0;
      int n = s.length();
      int i = 0;

      std::unordered_map<char,int> map;

      for( int j = 0 ; j < n ; j++ ) {
        map[s[j]]++;
        if( map[s[j]] == 1 ) {
          ret = std::max(ret, j-i+1);
        }
        else {
          while( map[s[j]] > 1){
            map[s[i]]--;
            i++;
          }
          ret = std::max(ret, j-i+1);
        }
      }
      return ret;
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

