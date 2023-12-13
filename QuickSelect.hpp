#include <iostream>
#include <vector>

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *(high - 1);
    std::vector<int>::iterator i = low - 1;

    for (std::vector<int>::iterator j = low; j < high - 1; ++j) {
        if (*j <= pivot) {
            ++i;
            std::swap(*i, *j);
        }
    }

    std::swap(*(i + 1), *(high - 1));
    return i + 1;
}

int quickSelect(std::vector<int>& nums, int k) {
    int low = 0;
    int high = nums.size();

    while (low < high) {
        std::vector<int>::iterator partition = hoarePartition(nums, nums.begin() + low, nums.begin() + high);
        int pivotIndex = std::distance(nums.begin(), partition);

        if (pivotIndex == k) {
            return *partition;
        } else if (pivotIndex < k) {
            low = pivotIndex + 1;
        } else {
            high = pivotIndex;
        }
    }

    // If k is out of bounds, return an appropriate value (e.g., -1).
    return -1;
}

