#include "SlidingWindow.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

SlidingWindow::SlidingWindow() {
  std::vector<int> testCase1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> testCase2 = {1};
  std::vector<int> testCase3 = {5, 4, -1, 7, 8};
  std::vector<int> testCase4 = {-1, -2};

  std::cout << maxSubArray(testCase1) << std::endl;
  std::cout << maxSubArray(testCase2) << std::endl;
  std::cout << maxSubArray(testCase3) << std::endl;
  std::cout << maxSubArray(testCase4) << std::endl;

  std::cout << maxSubArrayRecursive(testCase1) << std::endl;
  std::cout << maxSubArrayRecursive(testCase2) << std::endl;
  std::cout << maxSubArrayRecursive(testCase3) << std::endl;
  std::cout << maxSubArrayRecursive(testCase4) << std::endl;
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
  // Create a 2D array, initialized with all values to -1.
  // This a 2-row 2D array, having the 0/1 rows correlate to force true/false
  std::vector<std::vector<int>> dp(2, std::vector<int>(nums.size(), -1));
  return maxSubHelper(nums, 0, false, dp);
}

// The Dynamic Programming aspect of this is straightforward
// We've done the logic, all we have to do is check if a given
// function call has already been calculated.
int SlidingWindow::maxSubHelper(std::vector<int> &nums, int index, bool force,
                                std::vector<std::vector<int>> &dp) {
  // check out of bounds index
  size_t size = nums.size();
  if (index >= size) {
    return force ? 0 : INT_MIN;
  }
  // Check if we've been in this situation before
  if (dp[force][index] != -1) {
    return dp[force][index];
  }

  int left = 0, right = 0, ret = 0;

  if (force) {
    left = 0;
    right = nums[index] + maxSubHelper(nums, index + 1, true, dp);
    ret = std::max(left, right);
  } else {
    left = nums[index] + maxSubHelper(nums, index + 1, true, dp);
    right = maxSubHelper(nums, index + 1, false, dp);
    ret = std::max(left, right);
  }
  dp[force][index] = ret;
  return ret;
}
