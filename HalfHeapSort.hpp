#include <vector>
#include <algorithm>
#include <chrono>

inline std::vector<int>::size_type leftChild(std::vector<int>::size_type i) {
    return 2 * i + 1;
}

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole) {
    std::vector<int>::size_type child;
    int tmp = std::move(heap[hole]);

    for (; leftChild(hole) < heap.size(); hole = child) {
        child = leftChild(hole);
        if (child != heap.size() - 1 && heap[child] < heap[child + 1]) {
            ++child;
        }
        if (tmp < heap[child]) {
            heap[hole] = std::move(heap[child]);
        } else {
            break;
        }
    }
    heap[hole] = std::move(tmp);
}

void buildHeap(std::vector<int> &heap) {
    // Start from the last non-leaf node and perform percDown
    for (std::vector<int>::size_type i = heap.size() / 2; i != static_cast<std::vector<int>::size_type>(-1); --i) {
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int> &nums, int &duration) {
    auto start = std::chrono::steady_clock::now();

    // Build heap
    buildHeap(nums);

    // Remove n/2 elements from the heap
    for (std::vector<int>::size_type j = 0; j < nums.size() / 2; ++j) {
        // Move the first element to the end of the vector
        std::swap(nums[0], nums[nums.size() - 1 - j]);

        // Perform percDown to restore the heap property
        percDown(nums, 0);
    }

    // Median is now at the root of the remaining heap
    int median = nums[0];

    // Resize the vector
    nums.resize(nums.size() / 2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return median;
}
