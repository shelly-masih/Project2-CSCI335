// 3) Merge Sort
// You will implement the recursive part of the merge sort, and use std::merge
// for the merging. Since you can't really stop merge sort halfway through to
// get the median, run this sort to completion. Details: Since your end result
// will be a fully sorted vector either way, it doesn't matter whether the left
// side or right side contains the extra element when splitting an odd number.

#include "MergeSort.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>

int MergeSort::mergeSort(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::steady_clock::now();

  if (nums.size() <= 1) {
    auto end = std::chrono::steady_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
    return (nums[0]);
  }

  auto midpoint = nums.begin() + nums.size() / 2;
  std::vector<int> firsthalf(nums.begin(), midpoint);
  std::vector<int> secondhalf(midpoint, nums.end());

  mergeSort(firsthalf, duration);
  mergeSort(secondhalf, duration);

  std::merge(firsthalf.begin(), firsthalf.end(), secondhalf.begin(),
             secondhalf.end(), nums.begin());

  int size = nums.size();
  int median = 0;
  if (size % 2 == 0) { // checks if vector is even
    median = std::min(nums[size / 2 - 1], nums[size / 2]);
  } else { // if vector is odd
    median = nums[size / 2];
  }
  return median;
}