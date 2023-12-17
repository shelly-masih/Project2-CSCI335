#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

inline int leftChild(int i) { return 2 * i; }
void percDown(std::vector<int> &heap, std::vector<int>::size_type hole) {
  do {
    int child = leftChild(hole);

    // Check if there is a right child and if it's smaller than the left child
    if (child + 1 < heap.size() && heap[child + 1] < heap[child]) {
      ++child; // Use the right child instead
    }

    // If the child is smaller than heap[0], move the child up
    if (heap[child] < heap[0]) {
      heap[hole] = std::move(heap[child]);
    } else {
      break; // Found the right position for heap[0]
    }

    hole = child; // Update hole to the child's index for the next iteration

  } while (hole * 2 < heap.size());

  heap[hole] = std::move(heap[0]); // Move heap[0] down to the child position
}

void buildHeap(std::vector<int> &heap) {
  for (int parentNodeIdx = (heap.size() - 1) / 2; parentNodeIdx > 0;
       --parentNodeIdx) {
    heap[0] = heap[parentNodeIdx];
    percDown(heap, parentNodeIdx);
  }
}

int halfHeapSort(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::steady_clock::now();

  nums.push_back(nums[0]);
  buildHeap(nums);

  int size = (nums.size() - 2) / 2;
  int i = 0;
  while (i < size) {
    std::swap(nums[0], nums[nums.size() - 1]);
    nums.pop_back();
    percDown(nums, 1);
    ++i;
  }
  auto end = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                 .count();
  return nums[1];
}
