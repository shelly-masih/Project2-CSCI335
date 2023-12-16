#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                          std::vector<int>::iterator low,
                                          std::vector<int>::iterator high) {
  int pivot = *low;
  auto i = low;
  auto j = high;

  while (true) {
    do {
      ++i;
    } while (*i < pivot);

    do {
      --j;
    } while (*j > pivot);

    if (i >= j) {
      return j;
    }

    std::iter_swap(i, j);
  }
}

void medianOfThree(std::vector<int> &nums, std::vector<int>::iterator low,
                   std::vector<int>::iterator high) {
  auto mid = low + (high - low) / 2;

  if (*low > *mid)
    std::iter_swap(low, mid);
  if (*low > *high)
    std::iter_swap(low, high);
  if (*mid > *high)
    std::iter_swap(mid, high);
}

void QuickSelectHelper(std::vector<int> &nums,
  std::vector<int>::iterator lower,
  std::vector<int>::iterator upper,
  std::vector<int>::iterator middle) {
  
}

int quickSelect(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::high_resolution_clock::now();

  int k;

  if (nums.size() % 2 == 0) {
    k = (nums.size() / 2) - 1;
  } else {
    k = nums.size() / 2;
  }

  std::vector<int>::iterator low = nums.begin();
  std::vector<int>::iterator high = nums.end() - 1;
  std::vector<int>::iterator mid = std::next(nums.begin(), k);

  medianOfThree(nums, low, high);

  // Ensure the initial pivot is in the correct place
  std::vector<int>::iterator pivotIndex = hoarePartition(nums, low, high);

  while (low < high) {
    if (k < pivotIndex - nums.begin()) {
      high = pivotIndex;
    } else if (k > pivotIndex - nums.begin()) {
      low = pivotIndex + 1;
    } else {
      duration = std::chrono::duration_cast<std::chrono::microseconds>(
                     std::chrono::high_resolution_clock::now() - start)
                     .count();
      return *pivotIndex;
    }

    medianOfThree(nums, low, high);
    pivotIndex = hoarePartition(nums, low, high);
  }

  duration = std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::high_resolution_clock::now() - start)
                 .count();

  return *low;
}

