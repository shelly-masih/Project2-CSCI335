
#include <vector>

class QuickSelect {
  int quickSelect(std::vector<int> &nums, int &duration){
    // Record the start time
    auto start = std::chrono::steady_clock::now();

    int n = nums.size();
    int k = (n % 2 == 0) ? n / 2 : n / 2 + 1;

    // QuickSelect algorithm
    int low = 0;
    int high = n - 1;
    while (high - low > 10) {
      int pivot = medianOfThree(nums, low, high);
      auto pivotIt = std::partition(nums.begin() + low, nums.begin() + high,
                                    [pivot](int value) { return value < pivot; });

      // Swap pivot to its final position
      std::iter_swap(
          pivotIt, std::partition(nums.begin() + low, pivotIt,
                                  [pivot](int value) { return value == pivot; }));

      int pivotIndex = std::distance(nums.begin(), pivotIt);
      if (pivotIndex == k - 1) {
        break;
      } else if (pivotIndex < k - 1) {
        low = pivotIndex + 1;
      } else {
        high = pivotIndex - 1;
      }
    }

    // For small subarrays, use std::sort
    insertionSort(nums, low, high);

    int median = nums[k - 1];

    // Record the end time and calculate the duration
    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                   .count();

    return median;
  }
  std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                            std::vector<int>::iterator low,
                                            std::vector<int>::iterator high){
    auto pivot = *(high - 1);
    auto i = low - 1;

    for (auto j = low; j != high - 1; ++j) {
      if (*j <= pivot) {
        ++i;
        std::iter_swap(i, j);
      }
    }

    std::iter_swap(i + 1, high - 1);
    return i + 1;
                                            }

  int medianOfThree(std::vector<int>& nums, int low, int high){
    int mid = low + (high - low) / 2;
    if (nums[low] > nums[mid]) {
      std::swap(nums[low], nums[mid]);
    }
    if (nums[low] > nums[high]) {
      std::swap(nums[low], nums[high]);
    }
    if (nums[mid] > nums[high]) {
      std::swap(nums[mid], nums[high]);
    }
    return nums[mid];
    
  }
  void insertionSort(std::vector<int>& nums, int low, int high){
    for (int i = low + 1; i <= high; ++i) {
      int key = nums[i];
      int j = i - 1;

      while (j >= low && nums[j] > key) {
        nums[j + 1] = nums[j];
        --j;
      }

      nums[j + 1] = key;
    }
  }
};
