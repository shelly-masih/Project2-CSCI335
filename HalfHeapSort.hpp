// HalfHeapSort.hpp

#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

#include <vector>

#include "HalfHeapSort.hpp"
#include <algorithm>
#include <chrono>

inline int leftChild(int i) { return 2 * i + 1; }

void percDown(std::vector<int> &heap, int i, int n) {
  int child;
  int tmp;

  for (tmp = std::move(heap[i]); leftChild(i) < n; i = child) {
    child = leftChild(i);
    if (child != n - 1 && heap[child] < heap[child + 1])
      ++child;
    if (tmp < heap[child])
      heap[i] = std::move(heap[child]);
    else
      break;
  }
  heap[i] = std::move(tmp);
}

int halfHeapSort(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::steady_clock::now();
  int median;

  for (int i = nums.size() / 2 - 1; i >= 0; --i)
    percDown(nums, i, nums.size());
  for (int j = nums.size() / 2 - 1; j > 0; --j) {
    std::swap(nums[0], nums[j]);
    percDown(nums, 0, j);
  }

  if (nums.size() % 2 == 0) { // checks if vector is even
    median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
  } else { // if vector is odd
    median = nums[nums.size() / 2];
  }

  auto end = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                 .count();

  return median;
}





#endif
