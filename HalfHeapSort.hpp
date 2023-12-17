#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

inline int leftChild(int i) { return 2 * i; }
void percDown(std::vector<int> &heap, std::vector<int>::size_type hole) { // percolate down function
  do {
    int child = leftChild(hole);

    // Checks if there is a right child and if it's smaller than the left child
    if (child + 1 < heap.size() && heap[child + 1] < heap[child]) {
      ++child; // increment
    }

    // If the child is smaller than heap[0], move the child up
    if (heap[child] < heap[0]) {
      heap[hole] = std::move(heap[child]);
    } else {
      break; // finds the right position for heap[0]
    }

    hole = child; // Update hole to the child's index for the next iteration

  } while (hole * 2 < heap.size());

  heap[hole] = std::move(heap[0]); // Move heap[0] down to the child position
}

void buildHeap(std::vector<int> &heap) {
  // Start from the last non-leaf node and move up the tree
  for (int parentNode = (heap.size() - 1) / 2; parentNode > 0;
       --parentNode) {
    // Move the current parent node value to the root (index 0)
    heap[0] = heap[parentNode];
    // Restore the heap property by calling percDown
    percDown(heap, parentNode);
  }
}

int halfHeapSort(std::vector<int> &nums, int &duration) {
  auto start = std::chrono::steady_clock::now();

  nums.push_back(nums[0]);
  // build a max heap
  buildHeap(nums);

  // Calculate the size of the heap
  int size = (nums.size() - 2) / 2;
  int i = 0;

  // Iterate through the heap
  while (i < size) {
    std::swap(nums[0], nums[nums.size() - 1]);
    nums.pop_back();
    percDown(nums, 1);
    ++i;
  }
  auto end = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                 .count();
  // Return the minimum value in the sorted array
  return nums[1];
}
