#include <vector>
#include <iostream>
#include <chrono>

int halfSelectionSort(std::vector<int> &nums, int &duration) {
  int size = nums.size();
  int median;

  int half;
  if (size % 2 == 0) {
    half = size / 2;
  } else {
    half = (size / 2) + 1;
  }

  if (size > 50000) {
    std::cout << "The input is too big for selection sort" << std::endl;
    duration = -1;
  }

  auto start = std::chrono::steady_clock::now();
  for (auto it = nums.begin(); it != nums.begin() + half - 1; ++it) {
    auto minimum = it;
    for (auto jt = it + 1; jt != nums.begin() + half; ++jt) {
      if (*jt < *minimum) {
        minimum = jt;
      }
    }

    if (minimum != it) {
      std::iter_swap(it, minimum);
    }
  }

  if (size % 2 == 0) {
    median = (nums[half - 1] + nums[half]) / 2;
  } else {
    median = nums[half - 1];
  }

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
  duration = diff_sec.count();

  return median;
}
