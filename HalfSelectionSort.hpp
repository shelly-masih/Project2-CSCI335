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
        return 0;  
    }

    auto start = std::chrono::steady_clock::now();

    auto begin = nums.begin();
    auto endIterator = nums.end();  
    for (auto it = begin; it != endIterator - 1; ++it) {
        auto minIndex = it;
        for (auto jt = it + 1; jt != endIterator; ++jt) {
            if (*jt < *minIndex) {
                minIndex = jt;
            }
        }
        if (minIndex != it) {
            std::iter_swap(it, minIndex);
        }
        if (std::distance(begin, it) == size / 2) {
            break;
        }
    }
    auto half = std::next(begin, size / 2);
  if (size % 2 == 0) {
      auto secondHalf = std::next(begin, size / 2 - 1);
      median = std::min(*half, *secondHalf);
  } else {
      median = *half;
  }
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = diff.count();

    return median;
}
