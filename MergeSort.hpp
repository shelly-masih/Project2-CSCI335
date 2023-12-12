
#include <vector>
#include <iostream>

int mergeSort(std::vector<int>& nums, int& duration){
  auto start = std::chrono::steady_clock::now();

  if (nums.size() <= 1) {
    auto end = std::chrono::steady_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
    return (nums[0]);
  }

  auto midpoint = nums.begin() + nums.size() / 2;
  std::vector<int> firsthalf(nums.begin(), midpoint);
  std::vector<int> secondhalf(midpoint, nums.end());

  mergeSort(firsthalf, duration);
  mergeSort(secondhalf, duration);

  std::merge(firsthalf.begin(), firsthalf.end(), secondhalf.begin(),
             secondhalf.end(), nums.begin());

  int size = nums.size();
  int median = 0;
  if (size % 2 == 0) { // checks if vector is even
    median = std::min(nums[size / 2 - 1], nums[size / 2]);
  } else { // if vector is odd
    median = nums[size / 2];
  }
  return median;
}
