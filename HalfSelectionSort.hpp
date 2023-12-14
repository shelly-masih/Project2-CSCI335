#include <vector>
#include <iostream>
#include <chrono>
#include <iterator>

int halfSelectionSort(std::vector<int> &nums, int &duration) {
    int size = nums.size();
    int median;

    if (size > 50000) {
        std::cout << "The input is too big for selection sort" << std::endl;
        duration = -1;
        return 0;  // or return an appropriate value
    }

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(nums[i], nums[minIndex]);
        }

        // If we have reached the midpoint, break early to avoid unnecessary sorting
        if (i == size / 2) {
            break;
        }
    }

    int half = size / 2;
    median = nums[half - 1];

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    duration = diff_sec.count();

    return median;
}
