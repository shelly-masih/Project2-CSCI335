#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> worstCaseQuickSelect() {
    std::vector<int> vector_size(20000);

    // vector of size 2000
    for (int i = 0; i < 20000; ++i) {
        vector_size[i] = 20000 - i;
    }

    // return vector
    return vector_size;
}
