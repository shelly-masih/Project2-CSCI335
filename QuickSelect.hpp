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

void medianOfThree(std::vector<int>::iterator low,
                   std::vector<int>::iterator mid,
                   std::vector<int>::iterator high) {
  if (*low > *mid)
    std::iter_swap(low, mid);

  if (*low > *high)
    std::iter_swap(low, high);
  else if (*mid > *high)
    std::iter_swap(mid, high);

  // Ensure that the leftmost element is the pivot in case of equal values
  if (*low == *mid)
    std::iter_swap(low, high);
  else if (*low == *high)
    std::iter_swap(low, mid);
}

int recursiveQuickSelect(std::vector<int> &nums, int k,
                         std::vector<int>::iterator low,
                         std::vector<int>::iterator high) {
  std::vector<int>::iterator mid = std::next(nums.begin(), k);

  std::cout << "Value at loww: " << *low << std::endl;
  std::cout << "Value at mid: " << *mid << std::endl;
  std::cout << "Value at high: " << *high << std::endl;
  medianOfThree(low, mid, high);
  std::vector<int>::iterator pivotIndex = hoarePartition(nums, low, high);
  std::cout << "Pivot Index:  " << std::distance(nums.begin(), pivotIndex)
            << std::endl;

  if (k < pivotIndex - nums.begin()) {
    return recursiveQuickSelect(nums, k, low, pivotIndex); // Adjusted here
  } else if (k > pivotIndex - nums.begin()) {
    return recursiveQuickSelect(nums, k, pivotIndex + 1, high); // Adjusted here
  } else {
    return *pivotIndex;
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

  int result = recursiveQuickSelect(nums, k, nums.begin(), nums.end() - 1);

  duration = std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::high_resolution_clock::now() - start)
                 .count();

  return result;
}
