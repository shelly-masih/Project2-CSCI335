#include <vector>
#include <chrono>
#include <algorithm>

void inPlaceMergeSortHelper(std::vector<int>& nums, int begin, int end) {
    if (begin >= end) return;

    int mid = begin + (end - begin) / 2;
    inPlaceMergeSortHelper(nums, begin, mid);
    inPlaceMergeSortHelper(nums, mid + 1, end);

    std::inplace_merge(nums.begin() + begin, nums.begin() + mid + 1, nums.begin() + end + 1);
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();
    inPlaceMergeSortHelper(nums, 0, nums.size() - 1);
    auto finish = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

    int mid = nums.size() / 2;
    if (nums.size() % 2 == 0) {
        return nums[mid - 1];
    } else {
        return nums[mid];
    }
}
