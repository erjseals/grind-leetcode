#ifndef SLIDING_WINDOW_HPP
#define SLIDING_WINDOW_HPP

#include <vector>

class SlidingWindow
{
public:
	SlidingWindow();

private:
	int maxSubArray(std::vector<int>& nums);
	int maxSubArrayRecursive(std::vector<int>& nums);
};

#endif