#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int>::iterator medianOfThree(std::vector<int> &nums,
                                         std::vector<int>::iterator low,
                                         std::vector<int>::iterator high) {
  std::vector<int>::iterator left = low;
  std::vector<int>::iterator right = high;
  std::vector<int>::iterator mid = low + (high - low) / 2;

  if (*mid<*low && * mid> * high) {
    std::iter_swap(mid, right);
  }

  if (*mid > *low && *mid < *high) {
    std::iter_swap(mid, right);
  }

  if (*left<*mid && * left> * high) {
    std::iter_swap(left, right);
  }

  if (*left > *mid && *left < *high) {
    std::iter_swap(left, right);
  }

  return right;
}

std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                          std::vector<int>::iterator low,
                                          std::vector<int>::iterator high) {
  std::vector<int>::iterator pivot = medianOfThree(nums, low, high);
  std::vector<int>::iterator i = low;
  std::vector<int>::iterator j = pivot - 1;

  do {
    while (*i < *pivot) {
      ++i;
    }

    while (*j > *pivot) {
      --j;
    }

    if (i < j) {
      std::iter_swap(i, j);
      ++i;
      --j;
    }
  } while (i < j);

  std::iter_swap(i, pivot);
  return i;
}

void quickSelectHelperFunction(std::vector<int> &nums,
                               std::vector<int>::iterator low,
                               std::vector<int>::iterator high,
                               std::vector<int>::iterator mid) {
  if (std::distance(low, high) < 10) {
    std::sort(low, high + 1);
    return;
  }

  std::vector<int>::iterator pivot = hoarePartition(nums, low, high);
  if (pivot == mid) {
    return;
  } else if (pivot < mid) {
    quickSelectHelperFunction(nums, pivot + 1, high, mid);
  } else if (pivot > mid) {
    quickSelectHelperFunction(nums, low, pivot - 1, mid);
  }
}

int quickSelect(std::vector<int> &nums, int &duration) {
  auto start_time = std::chrono::high_resolution_clock::now();

  std::vector<int>::iterator low = nums.begin();
  std::vector<int>::iterator high = nums.end() - 1;
  std::vector<int>::iterator mid = nums.begin() + (nums.size() - 1) / 2;

  quickSelectHelperFunction(nums, low, high, mid);

  auto end_time = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                   start_time)
                 .count();

  return *(nums.begin() + (nums.size() - 1) / 2);
}
