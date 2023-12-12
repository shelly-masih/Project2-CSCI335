// HalfHeapSort.hpp

#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

#include <vector>

class HalfHeapSort {
public:
    int halfHeapSort(std::vector<int>& nums, int& duration);

    // Parameter "hole" is the index of the hole.
    // percDown precondition: value to be inserted into the hole is stored in heap at index 0. The hole itself may be an unspecified state - i.e it doesn't matter what's in it since you'll be overwriting it anyway.
    void percDown(std::vector<int>& heap, int i, int n);
    void buildHeap(std::vector<int>& heap, int n);
};

#endif  // HALFHEAPSORT_HPP