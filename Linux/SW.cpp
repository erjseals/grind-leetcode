#include "SW.hpp"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
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

namespace SW {

int minSubArrayLen(int target, std::vector<int>& nums) {
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

// You are given a string s and an integer k.
// You can choose any character of the string and 
// change it to any other uppercase English character.
// You can perform this operation at most k times.
//
// Return the length of the longest substring containing
// the same letter you can get after performing the above operations.
int characterReplacement(std::string s, int k) {
  std::unordered_map<char, int> map;
  int max = 0;
  int n = s.length();

  for(int i = 0, j = 0 ; j < n ; ) {
    map[s[j]]++;
    int windowSize = j - i + 1;
    
    int maxValue = 0;
    for (const auto& pair : map) {
        if (pair.second > maxValue) {
            maxValue = pair.second;
        }
    }

    if((windowSize - maxValue) <= k) {
      if(windowSize > max) {
        max = windowSize;
      }
      j++;
    }
    else {
      // Need to decrement s[j] since it's inc-ed every for loop
      // iteration. That needs to happen to make the maxValue
      // calculation correct. Could probably be more graceful, but
      // ** shrugs **
      map[s[j]]--;
      map[s[i]]--;
      i++;
    }
  }
  return max;
}

void test(){
  std::string s = "ABAB";
  int res = characterReplacement(s,2);
  if(res != 4){
    std::cout << "Test Failed. Expected 4, got " << res << std::endl;
  }
  else {
    std::cout << "Test Passed" << std::endl;
  }

  s = "AABABBA";
  res = characterReplacement(s,1);
  if(res != 4){
    std::cout << "Test Failed. Expected 4, got " << res << std::endl;
  }
  else {
    std::cout << "Test Passed" << std::endl;
  }

  s = "ABCDEF";
  res = characterReplacement(s,5);
  if(res != 6){
    std::cout << "Test Failed. Expected 6, got " << res << std::endl;
  }
  else {
    std::cout << "Test Passed" << std::endl;
  }
}

};
