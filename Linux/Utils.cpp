#include "Utils.hpp"

#include <algorithm>
#include <cstdint>
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

int Utils::minSubArrayLen(int target, std::vector<int>& nums) {
  bool set = false;
  int res = INT32_MAX;
  int n = nums.size();
  
  int currSum = 0;
  for(int i = 0, j = 0 ; j < n ; j+=1) {
    currSum += nums[j];
    
    while( currSum >= target ) {
      if( (j - i + 1) < res ) {
        res = j-i+1;
        if( !set ) set = true;
      }
      currSum -= nums[i];
      i += 1;
    }
  }
  if(!set) return 0;
  else return res;
}

// Given a string s, find the length of the longest substring without repeating characters.
int Utils::lengthOfLongestSubstring(std::string s) {
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

void Utils::test(){
  std::vector<int> nums = {2,3,1,2,4,3};
  int target = 7;

  int res = minSubArrayLen(target, nums);
  if( res == 2) {
    std::cout << "Test 1 pass" << std::endl;
  } else {
    std::cout << "Test 1 fail. Expected 2, got: " << res << std::endl;
  }

  nums = {1,1,1,1,1,1,1,1};
  target = 11;

  res = minSubArrayLen(target, nums);
  if( res == 0) {
    std::cout << "Test 2 pass" << std::endl;
  } else {
    std::cout << "Test 2 fail. Expected 0, got: " << res << std::endl;
  }

  
}
