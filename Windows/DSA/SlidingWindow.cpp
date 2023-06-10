#include "SlidingWindow.hpp"

#include <iostream>
#include <vector>

SlidingWindow::SlidingWindow() {
  std::vector<int> testCase1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> testCase2 = {1};
  std::vector<int> testCase3 = {5, 4, -1, 7, 8};

  std::cout << maxSubArray(testCase1) << std::endl;
  std::cout << maxSubArray(testCase2) << std::endl;
  std::cout << maxSubArray(testCase3) << std::endl;
}

int SlidingWindow::maxSubArray(std::vector<int> &nums) {
  int maxSum = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i, tempSum = 0; j < nums.size(); j++) {
      tempSum += nums[j];
      if (tempSum > maxSum) {
        maxSum = tempSum;
      }
    }
  }
  return maxSum;
}

int SlidingWindow::maxSubArrayRecursive(std::vector<int> &nums) {
  int maxSum = INT_MIN;
  return maxSum;
}
