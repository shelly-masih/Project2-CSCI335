#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <vector>

class QuickSelect {
public:
  int quickSelect(std::vector<int> &nums, int &duration);

private:
  std::vector<int>::iterator hoarePartition(std::vector<int> &nums,
                                            std::vector<int>::iterator low,
                                            std::vector<int>::iterator high);
  int medianOfThree(std::vector<int>& nums, int low, int high);
  void insertionSort(std::vector<int>& nums, int low, int high);
};

#endif


