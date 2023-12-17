
#include <vector>
#include <iostream>
#include <chrono>

int mergeSort(std::vector<int>& nums, int& duration){
  auto start = std::chrono::steady_clock::now();
// If the vector has one or zero elements, it is already sorted
  if (nums.size() <= 1) {
    auto end = std::chrono::steady_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
    // Return the single element in the sorted vector
    return (nums[0]);
  }

  // // Calculate the midpoint of the vector
  auto midpoint = nums.begin() + nums.size() / 2;
  // Create two vectors representing the first and second halves of the original vector
  std::vector<int> firsthalf(nums.begin(), midpoint);
  std::vector<int> secondhalf(midpoint, nums.end());
  // Recursively apply mergeSort to the first and second halves
  mergeSort(firsthalf, duration);
  mergeSort(secondhalf, duration);

  std::merge(firsthalf.begin(), firsthalf.end(), secondhalf.begin(),
             secondhalf.end(), nums.begin());
   // Calculate the size of the sorted vector
  int size = nums.size();
  int median = 0;
  // Determine the median value based on the size of the vector
  if (size % 2 == 0) { // checks if vector is even
    median = std::min(nums[size / 2 - 1], nums[size / 2]);
  } else { // if vector is odd
    median = nums[size / 2];
  }
   // Return the median value
  return median;
}
