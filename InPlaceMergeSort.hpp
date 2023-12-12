#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <vector>
#include <iostream>

class InPlaceMergeSort { 
    public:
        int inPlaceMergeSort(std::vector<int>& nums, int& duration);
        void inPlaceMergeSortHelper(std::vector<int>::iterator begin, std::vector<int>::iterator end, int &duration);
};

#endif