#include <vector>
#include <chrono>
#include <algorithm>

void inPlaceMergeSortHelper(std::vector<int>& nums, int begin, int end) { // Helper function for in-place merge sort
    if (begin >= end) return;

    // Calculate the middle index
    int mid = begin + (end - begin) / 2;
    // Recursively sort the left and right halves
    inPlaceMergeSortHelper(nums, begin, mid);
    inPlaceMergeSortHelper(nums, mid + 1, end);
    
    // Merge the sorted halves in-place
    std::inplace_merge(nums.begin() + begin, nums.begin() + mid + 1, nums.begin() + end + 1);
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    // Record the start time of the sorting process
    auto start = std::chrono::steady_clock::now();
    // Call the helper function 
    inPlaceMergeSortHelper(nums, 0, nums.size() - 1);
    auto finish = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    // Calculate the middle index
    int mid = nums.size() / 2;
     // Return the median value based on the size of the vector
    if (nums.size() % 2 == 0) {
        // If even, return the middle value
        return nums[mid - 1];
    } else {
        // If odd, return the middle value
        return nums[mid];
    }
}
