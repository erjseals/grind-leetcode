#ifndef SLIDING_WINDOW_HPP
#define SLIDING_WINDOW_HPP

#include <vector>

class SlidingWindow {
public:
  SlidingWindow();

  int maxSubArray(std::vector<int> &nums);
  int maxSubArrayRecursive(std::vector<int> &nums);

private:
  int maxSubHelper(std::vector<int> &nums, int index, bool force,
                   std::vector<std::vector<int>> &dp);
};

#endif