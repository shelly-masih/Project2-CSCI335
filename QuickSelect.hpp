#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int>::iterator medianOfThree(std::vector<int> &nums,
                                         std::vector<int>::iterator low,
                                         std::vector<int>::iterator high) {
  // Initialize iterators for left, right, and mid elements
  std::vector<int>::iterator left = low;
  std::vector<int>::iterator right = high;
  std::vector<int>::iterator mid = low + (high - low) / 2;

  // Swap the mid element with the right element if it is smaller than the low element
  if (*mid<*low && * mid> * high) {
    std::iter_swap(mid, right);
  }

  // Swap the mid element with the right element if it is greater than the low element
  if (*mid > *low && *mid < *high) {
    std::iter_swap(mid, right);
  }

  // Swap the left element with the right element if it is smaller than the mid element
  if (*left<*mid && * left> * high) {
    std::iter_swap(left, right);
  }
  
  // Swap the left element with the right element if it is greater than the mid element
  if (*left > *mid && *left < *high) {
    std::iter_swap(left, right);
  }
  
  // Return the iterator to the right element, which is the selected pivot
  return right;
}

std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                          std::vector<int>::iterator low,
                                          std::vector<int>::iterator high) {
  std::vector<int>::iterator pivot = medianOfThree(nums, low, high);
  std::vector<int>::iterator i = low;
  std::vector<int>::iterator j = pivot - 1;
   // Perform partitioning
  while (true) {
    while (*i < *pivot) {
      ++i;
    }
    while (*j > *pivot) {
      --j;
    }
    if (i >= j) {
      break;
    }
    std::iter_swap(i, j);
    ++i;
    --j;
  }
  // Swap the pivot into its final sorted position
  std::iter_swap(i, pivot);
  return i;
}

void quickSelectHelperFunction(std::vector<int> &nums,
                               std::vector<int>::iterator low,
                               std::vector<int>::iterator high,
                               std::vector<int>::iterator mid) { // helper function 
  if (std::distance(low, high) < 10) {
    std::sort(low, high + 1);
    return;
  }

  std::vector<int>::iterator pivot = hoarePartition(nums, low, high); // partitioning using Hoare's partition scheme
  if (pivot == mid) {
    return;
  } else if (pivot < mid) {
    // Recursively call quickSelect
    quickSelectHelperFunction(nums, pivot + 1, high, mid);
  } else if (pivot > mid) {
    quickSelectHelperFunction(nums, low, pivot - 1, mid);
  }
}

int quickSelect(std::vector<int> &nums, int &duration) {
  auto start_time = std::chrono::high_resolution_clock::now();

  // Initialize iterators for low, high, and mid elements
  std::vector<int>::iterator low = nums.begin();
  std::vector<int>::iterator high = nums.end() - 1;
  std::vector<int>::iterator mid = nums.begin() + (nums.size() - 1) / 2;
   // call helper function
  quickSelectHelperFunction(nums, low, high, mid);

  auto end_time = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                   start_time)
                 .count();
 // Return the median value
  return *(nums.begin() + (nums.size() - 1) / 2);
}
