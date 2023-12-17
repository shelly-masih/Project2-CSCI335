#include <vector>
#include <iostream>
#include <chrono>
#include <iterator>

int halfSelectionSort(std::vector<int> &nums, int &duration) {
    
 // Get the size of the vector
    int size = nums.size();
    int median;
    
// Checks if the input size is too large for selection sort
    if (size > 50000) {
        std::cout << "The input is too big for selection sort" << std::endl;
        duration = -1;
        return 0;  
    }

    auto start = std::chrono::steady_clock::now();
    
    // Iterate through the vector 
    auto begin = nums.begin();
    auto endIterator = nums.end();  
    // Find the minimum element in the unsorted portion of the array
    for (auto i = begin; i != endIterator - 1; ++i) {
        auto minIndex = i;
        for (auto j = i + 1; j != endIterator; ++j) {
            if (*j < *minIndex) {
                minIndex = j;
            }
        }
         // Swap the found minimum element with the current element
        if (minIndex != i) {
            std::iter_swap(i, minIndex);
        }
        // Check if the middle of the array is reached
        if (std::distance(begin, i) == size / 2) {
            break;
        }
    }
    // Calculate the iterator pointing to the middle element of the vector
    auto half = std::next(begin, size / 2);
    // Check if the vector size is even or odd
  if (size % 2 == 0) {
       // If even, calculate iterator pointing to the second half's middle element
      auto secondHalf = std::next(begin, size / 2 - 1);
      // Find the minimum value between the two middle elements
      median = std::min(*half, *secondHalf);
       // If odd, the median is the middle element itself
  } else {
      median = *half;
  }
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = diff.count();

    // Return the median value in the partially sorted array
    return median;
}
