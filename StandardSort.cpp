#include "StandardSort.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <vector>

int StandardSort::standardSort(std::vector<int> &nums, int &duration) {

  auto start = std::chrono::steady_clock::now(); // start the clock
  std::sort(nums.begin(), nums.end());           // sort the vector
  int size = nums.size();                        // get size of vector
  int median; // create variable to store the median

  if (size % 2 == 0) { // checks if vector is even
    median = std::min(nums[size / 2 - 1], nums[size / 2]);
  } else { // if vector is odd
    median = nums[size / 2];
  }
  auto end = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                 .count();

  return median;
}

