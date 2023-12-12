// 6) Quickselect
// Implement a quickselect algorithm, which works like a quicksort, except that
// after partitioning your array into the part that's less than your pivot and
// the part that's greater than your pivot, you only recurse on one side instead
// of both. To pick your pivot, use the "median of 3" method, which looks at the
// first, middle, and last element and picks the median of them as your pivot.
// Your quick select should be in-place. Details: For pivot selection, use the
// median of 3 method. This method takes the first element, last element, and
// middle element (or left-middle element if there are an even number of
// elements) and chooses the median of those as the pivot. If two or three of
// these share the same value, make the leftmost one your pivot. For
// partitioning, use the Hoare partition method, as described in textbook
// section 7.7.2. Swap values that are equal to the pivot (this prevents turning
// an input of identical values into a worst-case scenario). Consider edge
// cases, and make sure your iterators don't go out of bounds in any case. Keep
// in mind for Quickselect that once the pivot is placed, you recurse on one
// side of the pivot, not including the pivot (which is already in its correct
// position). hoarePartition will assume that the pivot is already in place, at
// the end of the subarray to be partitioned. Thus, you must swap your pivot
// into position before calling hoarePartition. A helper function for pivot
// selection and placement is advisable. Recursive base case: once your subarray
// size reaches 10 or less, use std::sort to sort it all rather than recursively
// calling QuickSelect. Additionally, you'll write a separate function to
// generate a vector of each integer from 1-20000 that will cause the
// quickselect algorithm to perform terribly - worst-case or close. Test this
// file on all methods, include it in your statistics, and briefly describe the
// approach you used at the end of your report.

// int quickSelect ( std::vector<int>& nums, int& duration )
// std::vector<int>::iterator hoarePartition ( std::vector<int>& nums,
// std::vector<int>::iterator low, std::vector<int>::iterator high )
//    // hoarePartition precondition: low points to the first element in the
//    subarray to be partitioned. The pivot is the last element in the subarray
//    to be partitioned, and is pointed to by high.
//    // hoarePartition returns an iterator to the pivot after it's placed.
// Note that this implementation of hoarePartition makes it usable with
// different pivot selection methods, but also requires that you select your
// pivot and swap it into the last position prior to calling hoarePartition.

// QuickSelect.cpp

// QuickSelect.cpp

#include "QuickSelect.hpp"
#include <algorithm>
#include <chrono>

int QuickSelect::quickSelect(std::vector<int> &nums, int &duration) {
  // Record the start time
  auto start = std::chrono::steady_clock::now();

  int n = nums.size();
  int k = (n % 2 == 0) ? n / 2 : n / 2 + 1;

  // QuickSelect algorithm
  int low = 0;
  int high = n - 1;
  while (high - low > 10) {
    int pivot = medianOfThree(nums, low, high);
    auto pivotIt = std::partition(nums.begin() + low, nums.begin() + high,
                                  [pivot](int value) { return value < pivot; });

    // Swap pivot to its final position
    std::iter_swap(
        pivotIt, std::partition(nums.begin() + low, pivotIt,
                                [pivot](int value) { return value == pivot; }));

    int pivotIndex = std::distance(nums.begin(), pivotIt);
    if (pivotIndex == k - 1) {
      break;
    } else if (pivotIndex < k - 1) {
      low = pivotIndex + 1;
    } else {
      high = pivotIndex - 1;
    }
  }

  // For small subarrays, use std::sort
  insertionSort(nums, low, high);

  int median = nums[k - 1];

  // Record the end time and calculate the duration
  auto end = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                 .count();

  return median;
}

std::vector<int>::iterator
QuickSelect::hoarePartition(std::vector<int> &nums,
                            std::vector<int>::iterator low,
                            std::vector<int>::iterator high) {
  auto pivot = *(high - 1);
  auto i = low - 1;

  for (auto j = low; j != high - 1; ++j) {
    if (*j <= pivot) {
      ++i;
      std::iter_swap(i, j);
    }
  }

  std::iter_swap(i + 1, high - 1);
  return i + 1;
}

int QuickSelect::medianOfThree(std::vector<int> &nums, int low, int high) {
  int mid = low + (high - low) / 2;
  if (nums[low] > nums[mid]) {
    std::swap(nums[low], nums[mid]);
  }
  if (nums[low] > nums[high]) {
    std::swap(nums[low], nums[high]);
  }
  if (nums[mid] > nums[high]) {
    std::swap(nums[mid], nums[high]);
  }
  return nums[mid];
}

void QuickSelect::insertionSort(std::vector<int> &nums, int low, int high) {
  for (int i = low + 1; i <= high; ++i) {
    int key = nums[i];
    int j = i - 1;

    while (j >= low && nums[j] > key) {
      nums[j + 1] = nums[j];
      --j;
    }

    nums[j + 1] = key;
  }
}
