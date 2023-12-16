#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

std::vector<int>::iterator medianOfThree(std::vector<int> &nums,
                                         std::vector<int>::iterator low,
                                         std::vector<int>::iterator high) {
  std::vector<int>::iterator mid = low + (high - low) / 2;

  if (*mid < *low) {
    std::iter_swap(mid, low);
  }
  if (*high < *low) {
    std::iter_swap(high, low);
  }
  if (*mid < *high) {
    std::iter_swap(mid, high);
  }

  return high;
}

std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                          std::vector<int>::iterator low,
                                          std::vector<int>::iterator high) {
  std::vector<int>::iterator pivot = medianOfThree(nums, low, high);
  std::vector<int>::iterator i = low - 1;
  std::vector<int>::iterator j = high + 1;

  do {
    do {
      ++i;
    } while (*i < *pivot);

    do {
      --j;
    } while (*j > *pivot);

    if (i >= j) {
      break;
    }

    std::iter_swap(i, j);
    ++i;
    --j;
  } while (true);

  std::iter_swap(i, pivot);
  return i;
}
void quickSelectHelper(std::vector<int> &nums, std::vector<int>::iterator low,
                       std::vector<int>::iterator high,
                       std::vector<int>::iterator mid) {
  if (std::distance(low, high) < 10) {
    std::sort(low, high + 1);
    return;
  }

  std::vector<int>::iterator pivotValue = hoarePartition(nums, low, high);
  if (pivotValue == mid) {
    return;
  } else if (pivotValue < mid) {
    quickSelectHelper(nums, pivotValue + 1, high, mid);
  } else if (pivotValue > mid) {
    quickSelectHelper(nums, low, pivotValue - 1, mid);
  }
}

int quickSelect(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::high_resolution_clock::now();

  int k;

  if (nums.size() % 2 == 0) {
    k = (nums.size() / 2) - 1;
  } else {
    k = nums.size() / 2;
  }

  // Example: Find the median

  std::vector<int>::iterator low = nums.begin();
  std::vector<int>::iterator high = nums.end() - 1;
  std::vector<int>::iterator mid = std::next(nums.begin(), k);

  quickSelectHelper(nums, low, high, mid);

  duration = std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::high_resolution_clock::now() - start)
                 .count();

  return *std::next(nums.begin(), k);
}

