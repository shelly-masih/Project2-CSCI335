#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

void inPlaceMergeSortHelper(std::vector<int>::iterator begin, std::vector<int>::iterator end, int &duration) {
    auto start = std::chrono::steady_clock::now();

    if (std::distance(begin, end) <= 1) {
        auto finish = std::chrono::steady_clock::now();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        return;
    }

    auto midpoint = begin + std::distance(begin, end) / 2;

    inPlaceMergeSortHelper(begin, midpoint, duration);
    inPlaceMergeSortHelper(midpoint, end, duration);

    std::inplace_merge(begin, midpoint, end);
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto begin = nums.begin();
    auto end = nums.end();

    auto start = std::chrono::steady_clock::now();
    inPlaceMergeSortHelper(begin, end, duration);
    auto finish = std::chrono::steady_clock::now();

    duration += std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

    int size = nums.size();
    int median;

    if (size % 2 == 0) { // checks if vector is even
        median = (nums[size / 2 - 1] + nums[size / 2]) / 2;
    } else { // if vector is odd
        median = nums[size / 2];
    }

    return median;
}
